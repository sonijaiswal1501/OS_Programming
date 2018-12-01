/*Implement a doubly linked list program with functions:
insert_at_beg, insert_at_end, delete_at_beg, delete_at_end & search.*/


#include<stdio.h>
#include<stdlib.h>


struct node{
	int val;
	struct node *next;
	struct node *prev;
};


struct node * insert_beg(struct node *head, int val)
{
	struct node *temp = head;
	struct node *newnode = (struct node*)malloc(sizeof(struct node));

	newnode->val = val;	
	newnode->prev = NULL;

	if(head == NULL)	
	  newnode->next = NULL;
		
	else 
	{ 	  
	   newnode->next = head;
	   head->prev = newnode;
	}
	head = newnode;	

	return head;

}
struct node * insert_end(struct node *head,int val)
{
	struct node *trav = head;

	struct node *newnode =  (struct node*)malloc(sizeof(struct node));
	newnode->val = val;
	newnode->next = NULL;	

	if(head == NULL)	
	  newnode->prev = NULL;	  
	 
	else
	{
	    while(trav->next != NULL)	
	      trav = trav->next;
	
	  trav->next = newnode;
	  newnode->prev = trav;	
	}
	 return head;

}
struct node * delete_beg(struct node *head)
{
	struct node *temp=NULL, *t_head;
	

	if(head == NULL)	
	  printf("\nList is empty\n");
	else
	{
	  temp=head;
	  head = temp->next;	   
	  head->prev = NULL;
	  free(temp);	
	}
	
	return head;
}
struct node * delete_end(struct node *head)
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


struct node * search(struct node *head, int val)
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

void display(struct node *head)
{
	struct node *trav = head;
	
	
	if(trav == NULL)
	{
	  printf("\nList is empty\n");
	  
	}
	
	printf("\nTraversal in Forward direction :: ");
	
	while(trav != NULL)
	{
	  printf("%d\t", trav->val);	 
	  trav = trav->next;
	}
	
	printf("\n");
}





