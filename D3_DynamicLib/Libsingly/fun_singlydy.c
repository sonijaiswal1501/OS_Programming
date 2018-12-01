/*Write a program to implement Singly Linked lists of integers.
1.Write function insert_end() to insert an element at end of linked list. Take Linked List pointer and integer as two arguments.
2.Write function insert_beg() to insert at beginning of linked list. Take Linked List pointer and integer as two arguments.
3.Write function delete_beg() & delete_end() to delete element from linked list. Take Linked List pointer only as single argument.
4.Write function search() to search as element in Linked list and return node address. Return NULL for failed search.
5.Write function insert_after() to insert an element after above search() function. Insert element at end for failed search().
6.Write function display() to print the elements of linked list. Take Linked List pointer only as single argument.*/


#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};


struct node* insert_beg(struct node *head, int val)
{
	struct node *temp = (struct node* )malloc(sizeof(struct node));

	temp->val = val;
	temp->next = NULL;

	if(head == NULL)	
	{
	  head = temp;
	  return head;
	}

	temp->next = head;
	head = temp;	

	return head;
}
struct node* insert_end(struct node *head, int val)
{
	struct node *temp = (struct node* )malloc(sizeof(struct node));
	struct node *t_head;

	temp->val = val;
	temp->next = NULL;

	if(head == NULL)	
	{
	  head = temp;
	  return head;
	}
	t_head = head;
	while(t_head->next != NULL)	
	  t_head = t_head->next;
	
	t_head->next = temp;

	return head;
}
struct node* delete_beg(struct node *head)
{
	struct node *temp;
	int val;

	if(head == NULL)	
	{
	  printf("\nList is empty\n");
	  return head;
	}
	
	val =  head->val;	
	temp = head;
	head = head->next;
	free(temp);

	return head;
}
struct node* delete_end(struct node *head)
{
	
	struct node *temp, *thead;

	if(head == NULL)	
	{
	  printf("\nList is empty\n");
	  return head;
	}
	
	thead = head;
	while(thead->next != NULL)
	{
	  temp = thead;
	  thead = thead->next;	
	}
	
	free(temp->next);
	temp->next = NULL;
	
	return head;
}
struct node* insert_after(struct node *head, int pos, int val)
{
	struct node *temp, *newNode; 
	newNode = (struct node*)malloc(sizeof(struct node));

	if(head == NULL)	
	{
	  printf("\nList is empty\n");
	  return head;
	}
	temp = head;
	while(temp != NULL)
	{
	  if(temp->val == pos)
	  {	    
	    newNode->val = val;
	    newNode->next = temp->next;
	    temp->next = newNode;

	    return head;
	  }
	  temp = temp->next;
	}
	printf("\nValue %d is not in the list \n", val);
	
	return head;

}
void display(struct node *head)
{
	if(head == NULL)
	 printf("\nList is empty\n");
	
	printf("\nValue is ");
	while(head != NULL)
	{
	  printf("%d\t", head->val);
	  head = head->next;
	}
}


struct node* search(struct node *head, int val)
{
	struct node *temp;

	temp = head; 	
	while(temp != NULL)
         {	    
	  if(temp->val == val)
	   {
	     printf("\nElement %d is found in the list \n", val);
	     return head;
	   }
	   temp = temp->next;		
	}
	printf("\nElement %d is not found in the list \n", val);
}




