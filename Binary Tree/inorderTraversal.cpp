#include <cstdio>
#include <cstdlib>
#include <iostream>
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

void inorderTraversal(btree *root) {
	if(root==NULL) return;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
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
	// root->left = new btree(2);
	// root->right = new btree(3);
	// root->left->left = new btree(4);
	// root->left->right = new btree(5);
	// root->right->left = new btree(6);
	// root->right->right = new btree(7);
	inorderTraversal(root);
	cout<<endl;
	return 0;
}