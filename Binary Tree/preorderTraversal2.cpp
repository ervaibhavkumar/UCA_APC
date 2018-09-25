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

void inorder(btree *root) {
	stack<btree*> stk;
	while(1) {
		while(root) {
			stk.push(root);
			cout<<root->data<<" ";
			root = root->left;
		}
		if(stk.empty()) return;
		btree *node = stk.top();
		stk.pop();
		root = node->right;
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

	inorder(root);
	cout<<endl;
	return 0;
}