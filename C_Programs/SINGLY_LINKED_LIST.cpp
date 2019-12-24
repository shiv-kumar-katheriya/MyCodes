#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
struct node
{
	int data;
	struct node *rlink;
} *head ;

//Function For traversing a list 
void Traversal(struct node *n1)
{
	if(n1 != NULL)
	{	
		while(n1 != NULL)
		{
			printf("\n\tData Is : %d",n1->data);
			n1 = n1->rlink;
		}
	}
	else
	{
		printf("\n\tSorry List Doesn't Exist First Create The List Then Try To Traverse a List  ");
	}
}


//Function For inserting a data in front of a list
Insert_Front(struct node *n1)
{
	n1 = (struct node*)malloc(sizeof(struct node));
	printf("\n\tEnter The Data : " );
	scanf("%d",&n1->data) ;
	n1->rlink = head;
	head = n1;
	printf("\n\tData Inserted Successfully ") ;		
}


//Function For inserting a data in Last of a list
Insert_Last(struct node *n2)
{
	if(n2 != NULL)
	{
		struct node *n1 ; 
		while(n2->rlink != NULL)
		{
			n2 = n2->rlink;
		}
		n1 = (struct node*)malloc(sizeof(struct node));
		printf("\n\tEnter The Data : " );
		scanf("%d",&n1->data) ;
		n1->rlink = NULL;
		n2->rlink = n1;
		printf("\tData Inserted Successfully ") ;		
	}
	else
	{
		printf("\n\tSorry List Doesn't Exist First Create The List Then Try To Insert data at last in the List  ");
	}
}


//Function For inserting a data in Middle of a list
Insert_Middle(struct node *n3)
{
	if(n3->rlink != NULL)
	{
		struct node *n1,*n2 ;
		int position;
		printf("\n\tEnter The Postion Where You Want To insert a Data : ");
		scanf("%d",&position); 
		while(position > 1)
		{
			n2 = n3 ;
			n3 = n3->rlink ;
			position = position - 1 ;
		}
		n1 = (struct node*)malloc(sizeof(struct node));
		printf("\n\tEnter The Data : " );
		scanf("%d",&n1->data) ;
		n2->rlink = n1;
		n1->rlink = n3;
		printf("\tData Inserted Successfully ") ;		
	}
	else
	{
		printf("\n\tSorry List Must Consist 2 or more then 2 Node    ");
	}
}


//function for deleting a data from front
Delete_Front(struct node *n1)
{	
	if(n1 != NULL)
	{
		head = n1->rlink ;
		free(n1);
		printf("\n\tData Deleted Successfully");
	}
	else
	{
		printf("\n\tSorry List Doesn't Exist First Create The List Then Try To Delete data From the List  ");
	}
}

	
//function for deleting a data from last
Delete_Last(struct node *n1)
{	
	if(n1 != NULL && n1->rlink != NULL)
	{
		while(n1->rlink->rlink != NULL)
		{
			n1 = n1->rlink ;
		}
		free(n1->rlink) ;
		n1->rlink = NULL ;
		printf("\n\tData Deleted Successfully");              
	}
	else
	{
				printf("\n\tSorry List Must Consist 2 or more then 2 Node then only you are able to Delete The last Node   ");
	}
}
		

//Function For deleting a data From Middle of a list
Delete_Middle(struct node *n3)
{
	if(n3 != NULL && n3->rlink != NULL)
	{
		struct node *n1,*n2 ;
		int position;
		printf("\n\tEnter The Postion Where You Want To Delete a Data : ");
		scanf("%d",&position); 
		while(position > 1)
		{
			n2 = n3 ;
			n3 = n3->rlink ;
			position = position - 1 ; 
		}
		n2->rlink = n3->rlink;
		free(n3) ;
		printf("\tData Deleted Successfully ") ;		
	}
	else
	{
		printf("\n\tSorry List Must Consist 2 or more then 2 Node    ");
	}
}


// main Block
int main()
	{
		struct node *n1 ;
		int choice ;
		printf("\n\n\t\t\t\t-:\t\tSingly Linked List\t\t:-\t\t") ;
		printf("\n\n\n\t****\tIntially the  List Is Empty\t****\t") ;
		printf("\n\n\tDo You Want To Enter The Data In The List ? ") ;
		printf("\n\tFor Yes Press -: 1") ;
		printf("\n\tFor No Press  -: 0") ;
		printf("\n\tPress : ") ;
		scanf("%d",&choice) ;
	
		if(choice == 1)
		{	
			n1 = (struct node*)malloc(sizeof(struct node));
			printf("\n\tEnter The Data  :  ") ;
			scanf("%d",&n1->data) ;
			n1->rlink = NULL ;
			head = n1 ;
			printf("\tData Inserted Successfully ") ;	
		}
	
			printf("\n\n\tDo you Want To Continue ?");
			printf("\n\tFor Yes Press -: 1") ;
			printf("\n\tFor No Press  -: 0") ;
			printf("\n\n\tPress : ") ;
			scanf("%d",&choice) ;
			while(choice == 1)
			{
				printf("\n\t*****  Choose Your Choice  ******  ");
				printf("\n\n\tFor Traversing a List Press  -: 1");
				printf("\n\tFor Insert a Data Press      -: 2");
				printf("\n\tFor Deleting a Data Press    -: 3");
				printf("\n\n\tPress : ") ;
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						Traversal(head);	
						break;
					case 2:
						printf("\n\tFor Insert a Data in Front Press  -: 1");
						printf("\n\tFor Insert a Data in Middle Press -: 2");
						printf("\n\tFor Insert a Data in Last Press   -: 3");
						printf("\n\n\tEnter Your Choice                 -:  ");
						scanf("%d",&choice);
							switch(choice)
							{
								case 1:
									Insert_Front(head);
									break;	
								case 2:
									Insert_Middle(head);
									break;				
								case 3:
									Insert_Last(head);
									break;		
								default : 
									printf("\n\tSorry You Entered A Wrong Choice");
									break;		
							}
						break;
					case 3:
						printf("\n\n\tFor Deleting a Data in Front Press  -: 1");
						printf("\n\tFor Deleting a Data in Middle Press -: 2");
						printf("\n\tFor Deleting a Data in Last Press   -: 3");
						printf("\n\n\tEnter Your Choice                 -:  ");
						scanf("%d",&choice);
							switch(choice)
							{
								case 1:
									Delete_Front(head);
									break;				
								case 2:
									Delete_Middle(head);
									break;				
								case 3:
									Delete_Last(head);
									break;		
								default : 
									printf("\n\tSorry You Entered A Wrong Choice");
									break;		
							}
						break;
					default : 
						printf("\n\tSorry You Entered A Wrong Choice");
						break;		
				}
				
				printf("\n\n\tDo you Want To Continue ?");
				printf("\n\tFor Yes Press -: 1") ;
				printf("\n\tFor No Press  -: 0") ;
				printf("\n\n\tPress : ") ;
				scanf("%d",&choice) ;
		}
		printf("\n\n\n\n\n\t\t\t\t********\tPractice Makes A Man Perfect\t********");
		printf("\n\n\n\n");
		return 0;
	}

