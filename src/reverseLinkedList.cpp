/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head==NULL)
		return NULL;
	struct node dummy;
	dummy.next = NULL;
	struct node* curr=head;
	while (curr != NULL)
	{
		struct node* element = curr;
		curr = curr->next;
		struct node* temp = dummy.next;
		dummy.next = element;
		element->next = temp;
	}
	return dummy.next;
}
