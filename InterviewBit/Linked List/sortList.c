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

node *merge(node *A , node *B) {
	if(A == NULL){
        return B;
    }
    if(B == NULL){
        return A;
    }
    
    node* head = NULL;
    
    if(A->data < B->data){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    
    node* temp = head;
    
    while(A != NULL && B != NULL){
        if(A->data < B->data){
            temp->next = A;
            A = A->next;
        }
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    
    if(A != NULL){
        temp->next = A;
    }
    else{
        temp->next = B;
    }
    
    return head;
}

node *sort(node *head) {
	if(head==NULL||head->next==NULL) return head;

	node *fast = head->next , *slow = head;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	node *l = head , *r = slow->next;
	slow->next = NULL;
	l = sort(l);
	r = sort(r);
	return merge(l,r);
}

int main()
{
	node *head = NULL;
	addAtLast(&head,1);
	addAtLast(&head,5);
	addAtLast(&head,32);
	addAtLast(&head,2);
	addAtLast(&head,92);
	printList(head);
	node *h = sort(head);
	printList(h);
	return 0;
}