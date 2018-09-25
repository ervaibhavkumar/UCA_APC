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

int sameTrees(btree *a , btree *b) {
	if(a&&b) {
		if(a->data != b->data) return 0;

		return (sameTrees(a->left,b->left)) && (sameTrees(a->right,b->right));
	}
	if(a==NULL && b==NULL) return 1;
	return 0; 
}

int main()
{
	btree *a = NULL;
	a = makeTree(a,1);
	a = makeTree(a,2);
	a = makeTree(a,3);
	a = makeTree(a,4);
	a = makeTree(a,5);
	a = makeTree(a,6);
	a = makeTree(a,7);

	btree *b = NULL;
	b = makeTree(b,1);
	b = makeTree(b,2);
	b = makeTree(b,3);
	b = makeTree(b,4);
	b = makeTree(b,5);
	b = makeTree(b,6);
	b = makeTree(b,7);
	cout<<sameTrees(a,b);
	return 0;
}