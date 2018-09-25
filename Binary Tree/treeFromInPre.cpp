#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>

using namespace std;

typedef struct btree {
	int data;
	struct btree *left;
	struct btree *right;
}btree;

btree *makeTree(int *in , int *pre , int start , int end , int *index) {
	if(start>end) return NULL;

	btree *nn = (btree*)malloc(sizeof(btree));
	nn->data = pre[*index];
	int i;
	for(i=start;i<=end;i++) {
		if(pre[*index] == in[i]) {
			break;
		}
	}
	(*index)++;
	nn->left = makeTree(in,pre,start,i-1,index);
	nn->right = makeTree(in,pre,i+1,end,index);
	return nn;
}

void printTree(btree *root) {
	if(root==NULL) return;

	queue<btree*> q;
	q.push(root);
	// printf("%d\n",root->data);
	while(!q.empty()) {
		btree *node = q.front();
		q.pop();
		printf("%d\n",node->data);
		if(node->left) {
			q.push(node->left);	
		}
		if(node->right) {
			q.push(node->right);
		}
	}
}

int main()
{
	int pre[] = {1,2,4,5,3,6,7};
	int in[] = {4,2,5,1,6,3,7};
	int index = 0;
	btree *root = makeTree(in,pre,0,6,&index);

	printTree(root);
	return 0;
}