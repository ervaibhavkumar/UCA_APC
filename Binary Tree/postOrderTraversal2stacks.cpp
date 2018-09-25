#include <iostream>
#include <stack>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct btree {
	int data;
	struct btree *left;
	struct btree *right;
}btree;

btree *makeTree(btree *root, int d) {
	btree *nn = (btree*)malloc(sizeof(btree));
	nn->data = d;
	nn->left = NULL;
	nn->right = NULL;

	if(root==NULL) return nn;

	queue<btree*> q;
	q.push(root);

	while(!q.empty()) {
		btree *node = q.front();
		q.pop();
		if(node->left) {
			q.push(node->left);
		}
		else {
			node->left = nn;
			return root;
		}
		if(node->right) {
			q.push(node->right);
		}
		else {
			node->right = nn;
			return root;
		}
	}
}

void postOrder(btree *root) {
	stack<btree*> stk1;
	stack<btree*> stk2;

	stk1.push(root);
	btree *node;
	while(!stk1.empty()) {
		node = stk1.top();
		stk1.pop();
		stk2.push(node);
		if(node->left) {
			stk1.push(node->left);
		}
		if(node->right) {
			stk1.push(node->right);
		}
	}

	while(!stk2.empty()) {
		node = stk2.top();
		stk2.pop();
		cout<<node->data<<" ";
	}
}

int main()
{
	btree *root = NULL;
	root = makeTree(root,1);
	root = makeTree(root,2);
	root = makeTree(root,3);
	root = makeTree(root,4);
	root = makeTree(root,5);
	root = makeTree(root,6);
	root = makeTree(root,7);

	postOrder(root);
	cout<<endl;
	return 0;
}