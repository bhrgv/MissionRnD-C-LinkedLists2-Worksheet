/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<=0)
		return NULL;
	int kstep = 0;
	struct node* curr = head;
	while (curr != NULL)
	{
		if (kstep == K-1){
			struct node* temp = curr->next;
			curr->next = (struct node*)malloc(sizeof(struct node));
			curr->next->next = temp;
			curr->next->num = K;
			curr = temp;
		}
		else
			curr = curr->next;
		kstep = (kstep + 1) % K;
	}
	return head;
}
