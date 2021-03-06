#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

typedef struct btree {
	int data;
	struct btree *left;
	struct btree *right;
}btree;

btree *makeTree(btree *root , int d) {
	btree *nn = (btree*)malloc(sizeof(btree));
	nn->data = d;
	nn->left = NULL;
	nn->right = NULL;
	if(root==NULL) {
		return nn;
	}
	else {
		queue<btree*> q;
		q.push(root);
		while(!q.empty()) {
			btree *node = q.front();
			q.pop();
			if(node->left) q.push(node->left);
			else {
				node->left = nn;
				return root;
			}

			if(node->right) q.push(node->right);
			else {
				node->right = nn;
				return root;
			}
		}
	}
}

int max(int a , int b) {
	if(a>b) return a;
	return b;
}

int maxSum(btree *root) {
	if(root==NULL) return 0;
	return root->data + max(maxSum(root->left),maxSum(root->right));
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
	
	cout<<maxSum(root)<<endl;
	return 0;
}