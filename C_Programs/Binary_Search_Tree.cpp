#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *llink;
	struct node *rlink;
	int data;
}*head;


struct node	Create_Left_Sub_tree(struct node *n1, int value);
//struct node	Delete(struct node *n1, int value)
//{
//	printf("\n\n\tElement Deleted ");
//}

// creating a function for insert a value in right sub tree
struct node	Create_Right_Sub_tree(struct node *n1, int value)
{
	if(n1->rlink==NULL)
	{
		n1->rlink = (struct node*)malloc(sizeof(struct node));
		n1=n1->rlink;
		n1->data=value;
		n1->llink=NULL;
		n1->rlink=NULL;
	}
	else
	{	
		n1=n1->rlink;
		if(value>n1->data)
		{	
			
			Create_Right_Sub_tree(n1,value);
		}
		else
		{
			Create_Left_Sub_tree(n1,value);
		}
	}
}

// creating a function for insert a value in left sub tree
struct node	Create_Left_Sub_tree(struct node *n1, int value)
{
	if(n1->llink==NULL)
	{
		n1->llink = (struct node*)malloc(sizeof(struct node));
		n1=n1->llink;
		n1->data=value;
		n1->llink=NULL;
		n1->rlink=NULL;
	}
	else
	{	
		n1=n1->llink;
		if(value>n1->data)
		{	
			
			Create_Right_Sub_tree(n1,value);
		}
		else
		{
			Create_Left_Sub_tree(n1,value);
		}
	}
}

//Pre Order Traversal 
struct node Pre_Order_Traversal(struct node *n1)
{
	if(n1!=NULL)
	{
		printf("\n\n\t\t*\t\tData Is :: %d ",n1->data);
		Pre_Order_Traversal(n1->llink);
		Pre_Order_Traversal(n1->rlink);
	}
	
}

//In Order Traversal 
struct node In_Order_Traversal(struct node *n1)
{
	if(n1!=NULL)
	{
		In_Order_Traversal(n1->llink);
		printf("\n\n\t\t*\t\tData Is :: %d ",n1->data);
		In_Order_Traversal(n1->rlink);
	}
	
}


//Post Order Traversal 
struct node Post_Order_Traversal(struct node *n1)
{
	if(n1!=NULL)
	{
		Post_Order_Traversal(n1->llink);
		Post_Order_Traversal(n1->rlink);
		printf("\n\n\t\t*\t\tData Is :: %d ",n1->data);
	}
	
}
	
int main()
{
	int value,choice;
	struct node *n1;
	
	printf("\n\n\n\t\t\t\t\t-:\t\tBinary Search Tree\t\t:-\n\n");
	printf("\n\n\t\t*\t\tEnter The data : ");
	n1 = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&n1->data);
	head=n1;
	n1->rlink=NULL;
	n1->llink=NULL;
	printf("\n\n\t\t*\t\tDo You Want More Data (for Yes 1/ for No 0) : ");
	scanf("%d",&choice);
	while(choice==1)
	{
		printf("\n\n\t\t*\t\tEnter The data : ");
		scanf("%d",&value);
		if(value>n1->data)
		{
			Create_Right_Sub_tree(head,value);
		}
		else
		{
			Create_Left_Sub_tree(head,value);
		}
		printf("\n\n\t\t*\t\tDo You Want More Data (for Yes 1/ for No 0) : ");
		scanf("%d",&choice);
	}
	printf("\n\n\t\t*\t\tChoose Your Choice            -:: ");
	printf("\n\n\t\t*\t\tFor Pre ORDER Traverse Press  -:: 1\n\n\t\t*\t\tFor IN ORDER Traverse Press  -:: 2\n\n\t\t*\t\tFor Post ORDER Traverse Press -:: 3");
	printf("\n\n\t\t*\t\tEnter Your Choice             -:: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				Pre_Order_Traversal(head);
				break;
		case 2:
				In_Order_Traversal(head);
				break;
		case 3:
				Post_Order_Traversal(head);
				break;
		default : 
				printf("\n\n\t\t*\t\tYou Entered  a Wrong Choice");
				break;		
	}
	printf("\n\n\n\n\n\t\t\t\t\t********Practice Makes A Man Perfect*********");
	printf("\n\n\n\n");
	return 0;
}
