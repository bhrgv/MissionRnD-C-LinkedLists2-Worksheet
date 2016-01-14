/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node dummy;
	struct node* curr=&dummy;
	struct node* curr1 = head1;
	struct node* curr2 = head2;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	while (curr1 != NULL&&curr2 != NULL)
	{
		if (curr1->num < curr2->num)
		{
			curr->next = curr1;
			curr1 = curr1->next;
			curr = curr->next;
			curr->next = NULL;
		}
		else
		{
			curr->next = curr2;
			curr2 = curr2->next;
			curr = curr->next;
			curr->next = NULL;
		}
	}
	while (curr1 != NULL)
	{
		curr->next = curr1;
		curr1 = curr1->next;
		curr = curr->next;
		curr->next = NULL;
	}
	while (curr2 != NULL)
	{
		curr->next = curr2;
		curr2 = curr2->next;
		curr = curr->next;
		curr->next = NULL;
	}
	return dummy.next;
}
