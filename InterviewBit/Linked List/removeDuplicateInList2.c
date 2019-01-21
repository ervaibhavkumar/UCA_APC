#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node *createNode(int d) {
	node *nn = (node *)malloc(sizeof(node *));
	nn->data = d;
	nn->next = NULL;
	return nn;
}

void addAtBeg(node **h , int d) {
	node *curr = createNode(d);
	*h = curr;
}

void addAtLast(node **h , int d) {
	if (*h==NULL) {
		addAtBeg(h,d);
	}
	else{
		node *curr = *h;
		while(curr && curr->next) {
			curr = curr->next;
		}
		node *temp = createNode(d);
		curr->next = temp;
	}
}

void addAtGivenPos(node **h , int d , int pos) {
	if(*h == NULL) {
		addAtBeg(h,d);
	}
	else {
		node *curr = *h;
		int  p =1;
		while(curr && p < pos-1) {
			curr = curr->next;
			p++;
		}
		if(curr==NULL) {
			printf("Position don't exist\n");
			return;
		}
		node *temp = createNode(d);
		temp->next = curr->next;
		curr->next = temp;
	}
}

int deleteAtBeg(node **h) {
	node *temp;
	if(*h == NULL) {
		return -1;
	}
	else if( (*h)->next == NULL) {
		temp = *h;
		*h = NULL;
	}
	else {
		temp = *h;
		*h = (*h)->next;
	}
	int data = temp->data;
	free(temp);
	temp = NULL;
	return data;
}

int deleteAtLast(node **h) {
	if(*h == NULL) {
		return -1;
	}
	else {
		node *curr = *h;
		while(curr && curr->next && curr->next->next) {
			curr = curr->next;
		}
		node *c = curr->next;
		int data = c->data;
		free(c);
		c = NULL;
		return data;
	} 
}

int deleteAtGivenPos(node **h , int pos) {
	if(pos==1) {
		return deleteAtBeg(h);
	}
	else {
		node *curr = *h;
		int p = 1;
		while(curr && curr->next && p < pos-1) {
			curr = curr->next;
			p++;
		}
		if(curr==NULL && curr->next == NULL) {
			printf("Position don't exist\n");
			return -1;
		}
		node *temp = curr->next;
		int data = temp->data;
		free(temp);
		temp = NULL;
		return data;
	}
}

void printList(node *h) {
	while(h!=NULL) {
		printf("%d\n",h->data);
		h = h->next;
	}
}

void removeDuplicates(node *h) {
	node *curr = h;
	node *next;
	node *temp;

	if(h==NULL) return;

	while(curr->next!=NULL) {
		if(curr->data == curr->next->data) {
			next = curr->next->next;
			temp = curr;
			free(temp);
			free(curr->next);
			curr->next = next;
		}
		else {
			curr = curr->next;
		}
	}
}

int main()
{
	node *head = NULL;
	addAtLast(&head,1);
	addAtLast(&head,1);
	addAtLast(&head,2);
	addAtLast(&head,2);
	addAtLast(&head,3);
	printf("Before\n");
	printList(head);
	removeDuplicates(head);
	printf("After\n");
	printList(head);
	return 0;
}