#include<stdio.h>
#include"avl.h"

int main()
{
	int key,ch,ch1,res;
	
	node_t* root;
	
	init(&root);
do
{
	
	printf("\n\n******MENU*******\n0.EXIT\n1.MAKE TREE\n2.DISPLAY TREE\n3.SEARCH FOR AN ELEMENT\n");
	printf("Enter the choice: ");
	scanf("%d",&ch);


	switch(ch)
	{
		case 1: do
			{
				printf("\nEnter the key element:");
				scanf("%d",&key);
		
				make_tree(&root,key);

				printf("\ndo u want to continue::1 or 0\n");
				scanf("%d",&ch1);
			}while(ch1);
			
			printf("\nbefore balance\n");
			printf("NODES\tBALANCE FACTOR\n");
			display(root);

			check_imbalance(root,&root);
			break;

		case 2: if(root)
			{
				 printf("\nafter balance\n");
				printf("NODES\tBALANCE FACTOR\n");

				display(root);
			}
			else 
				printf("\ntree is empty\n");
			break;

	    	case 3:// node_t* temp;
	
			printf("\nEnter the element to be searched: ");
			scanf("%d",&key);
			 node_t* temp;
			temp=search(root,key);
			if(temp)
			{
				printf("Element %d is found in the tree\n",key);
			}
			else
			{
				printf("\nElement %d is not found in the tree\n",key);
			}
			break;
		case 0: printf("\n****THANK YOU****\n****VISIT AGAIN****\n");
			break;
		default: printf("\ninvalid  choice\n");
			break;


	}
	
}while(ch);

return 0;
}
