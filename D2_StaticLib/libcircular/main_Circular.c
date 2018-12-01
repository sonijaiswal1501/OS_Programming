/*Write an Implementation of Circular Linked insert_front, insert_end and display functions.*/

#include<stdio.h>
#include<stdlib.h>
#include"Circular.h"



int main()
{
	int i, n, ch, data;
	struct node *head = NULL;

	do
	{
	 printf("\n\n\n-----------Circular Linked List------------:\n");
	 printf("\n\n1. Insert at beg.\n");	 
	 printf("\n2. Insert_end.\n");	 
	 printf("\n3. Display.\n");
	 printf("\n0. Exit\n");
	
	 printf("\nEnter the choice :");
	 scanf("%d", &ch);

	 switch(ch)
	 {
	   case 1:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
		  {
	   	    printf("\nEnter the value ");
	   	    scanf(" %d", &data);
	   	    head = insert_beg(head, data);	
	   	    display(head);
	 	  }
		  break;	 

	   case 2:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
		  {
	   	    printf("\nEnter the value ");
	   	    scanf(" %d", &data);
	   	    head = insert_end(head, data);	
	   	    display(head);
	 	  }
		  break;

	   case 3:display(head);
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	
	printf("\n");

	return 0;
}





