/*Write an Implementation of Circular Linked insert_front, insert_end and display functions.*/

#include<stdio.h>
#include<stdlib.h>


struct node{
	int val;
	struct node *next;
};


struct node *insert_beg(struct node *head, int val)
{
	struct node *current = NULL;
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->val = val;
	temp->next = NULL;

	if(head == NULL)	
	{
	  head = temp;
	  head->next = temp;
	  return head;
	}

	current = head;
	while(current->next != head)
	   current = current->next;

	current->next = temp;
	temp->next = head;
	head = temp;	

	return head;
	
}
struct node *insert_end(struct node *head, int val)
{
	struct node *current = NULL;
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->val = val;
	temp->next = NULL;

	if(head == NULL)	
	{
	  head = temp;
	  head->next = temp;
	  return head;
	}

	current = head;
	while(current->next != head)
	   current = current->next;

	current->next = temp;
	temp->next = head;
	
	return head;	
}

void display(struct node *head)
{
	struct node *temp = head;

	if(head == NULL)
	 printf("\nList is empty\n");
	
	printf("\nValue is :: ");
	while(temp->next != head)
	{
	  printf("%d\t", temp->val);
	  temp = temp->next;
	}
	printf("%d\t", temp->val);
}





