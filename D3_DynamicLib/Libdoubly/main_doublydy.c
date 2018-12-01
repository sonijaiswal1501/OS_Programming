/*Implement a doubly linked list program with functions:
insert_at_beg, insert_at_end, delete_at_beg, delete_at_end & search.*/


#include<stdio.h>
#include<stdlib.h>
#include"doubly.h"

int main()
{
	int i, n, ch, data, pos;
	struct node *head = NULL;

	do
	{
	 printf("\n\n\n-----------Doubly Linked List------------:\n");
	 printf("\n\n1. Insert at beg.\n");
	 printf("\n2. Insert at end.\n");
	 printf("\n3. Delete at beg.\n");
	 printf("\n4. Delete at end.\n");
	 printf("\n5. Search.\n");	
	 printf("\n6. Display.\n");
	 printf("\n0. Exit\n");
	
	 printf("\nEnter the choice :");
	 scanf("%d", &ch);

	 switch(ch)
	 {
	   case 1:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
	 	  {
	   	     printf("\nEnter the value of element : ");
		     scanf(" %d", &data);
	             head = insert_beg(head, data);
		     display(head);
		  }
		  break;
		
	   case 2:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
	 	  {
	   	     printf("\nEnter the value of element : ");
		     scanf(" %d", &data);
		     head = insert_end(head, data);
		     display(head);
		  }		 
		  break;
	
	   case 3:head = delete_beg(head);
		  display(head);
		  break;

	   case 4:head = delete_end(head);
		  display(head);
		  break;

	   case 5:printf("\nEnter the value ");
		  scanf(" %d", &data);
		  search(head, data);
		  break;
	   
	   case 6:display(head);
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}
