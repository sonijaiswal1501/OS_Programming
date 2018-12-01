
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main()
{	
	int i, n, ch, data, pos;
	
	do
	{
	 printf("\n\n\n-----------Stack using Linked List------------:\n");
	 printf("\n\n1. Push the element.\n");
	 printf("\n2. Pop the element.\n");
	 printf("\n3. Display\n");
	 printf("\n0. Exit\n");	
	
	 printf("\nEnter the choice :");
	 scanf("%d", &ch);

	 switch(ch)
	 {
	   case 1:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
	 	  {
		    printf("\nEnter the value to be insert: ");
		    scanf(" %d", &data);
	            push(data);
		  }
		    display();
		    break;
		
	   case 2:pop();
		  display();
		  break;
	
	   case 3:display();
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}

