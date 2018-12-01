
#include<stdio.h>
#include<stdlib.h>
#include"singly1.h"



int main()
{
	int ch, data, pos;
	struct node *head = NULL;

	do
	{
	 printf("\n\n\n-----------Singly Linked List------------:\n");
	 printf("\n\n1. Insert at beg.\n");
	 printf("\n2. Insert at end.\n");
	 printf("\n3. Delete at beg.\n");
	 printf("\n4. Delete at end.\n");
	 printf("\n5. Search.\n");
	 printf("\n6. Insert after.\n");
	 printf("\n7. Display.\n");
	 printf("\n0. Exit\n");
	
	 printf("\nEnter the choice :");
	 scanf("%d", &ch);

	 switch(ch)
	 {
	   case 1:printf("\nEnter the value ");
		  scanf(" %d", &data);
	          head = insert_beg(head, data);
		  display(head);
		  break;
		
	   case 2:printf("\nEnter the value ");
		  scanf(" %d", &data);
		  head = insert_end(head, data);
		  display(head);
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
		  display(head);
		  break;

	   case 6:printf("\nEnter the item after ");
		  scanf(" %d", &pos);
		  printf("\nEnter the value ");
		  scanf(" %d", &data);
		  insert_after(head, pos, data);
		  display(head);
		  break;

	   case 7:display(head);
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}

