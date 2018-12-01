//Write a program to implement Stack using Linked List .


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*top = NULL;


void push(int val)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	  
	newnode->data = val;
	
	if(top == NULL)
	   newnode->next = NULL;
	else
	  newnode->next = top;
	top= newnode;
}
void pop(void)
{
	struct node *temp;
	
	if(top == NULL)
	    printf("\nStack is empty\n");
	
	temp = top;
	top= top->next;
	free(temp);
	
}

void display(void)
{	
	struct node *temp = top;
	if(top == NULL)
	 printf("\nStack is empty\n");	
	
	printf("\nValue is :: ");
	while(temp != NULL)
	{
	      printf(" %d\t", temp->data);
	      temp = temp->next;
	}
	
}



		



