#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *llink;
	struct node *rlink;
	struct node *pz;
	int data;
	char col;
}*head;


struct node RbTreeFixup(struct node *n2);

struct node Create_Right_Sub_tree(struct node* n1, int value);
struct node Create_Left_Sub_tree(struct node* n1, int value);

struct node BST_Rotate_Right(struct node* n1);
struct node BST_Rotate_Left(struct node* n1);

struct node In_Order_Traversal(struct node *n1);
struct node Pre_Order_Traversal(struct node *n1);
struct node Post_Order_Traversal(struct node *n1);


//Pre Order Traversal 
struct node Pre_Order_Traversal(struct node *n1)
{
	if(n1!=NULL)
	{
		printf("\n\n\t\t*\t\tData Is :: %d  %c ",n1->data,n1->col);
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
		printf("\n\n\t\t*\t\tData Is :: %d  %c ",n1->data,n1->col);
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
		printf("\n\n\t\t*\t\tData Is :: %d  %c ",n1->data,n1->col);
	}
	
}


// creating a function for insert a value in left sub tree
struct node	Create_Left_Sub_tree(struct node *n1,int value)
{
	//printf("LST");
	if(n1->llink==NULL)
	{
		struct node *n2;
		n2= (struct node*)malloc(sizeof(struct node));
		n2->pz=n1;
		n1->llink=n2;
		n2->data=value;
		n2->col='R';
		n2->llink=NULL;
		n2->rlink=NULL;
		RbTreeFixup(n2);
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



// creating a function for insert a value in right sub tree
struct node	Create_Right_Sub_tree(struct node *n1, int value)
{
	//printf("RST");
	if(n1->rlink == NULL)
	{
		struct node *n2;
		n2= (struct node*)malloc(sizeof(struct node));
		n1->rlink = n2;
		n2->data = value;
		n2->pz = n1;
		n2->col = 'R';
		n2->llink = NULL;
		n2->rlink = NULL;
		RbTreeFixup(n2);
	}
	else
	{	
		n1 = n1->rlink;
		if(value > n1->data)
		{	
			Create_Right_Sub_tree(n1,value);
		}
		else
		{
			Create_Left_Sub_tree(n1,value);
		}
	}
}


//funtion for RB Tree Fix Up
struct node RbTreeFixup(struct node *n2)
{	 
	//printf("\nFixup");
	struct node *uncle; 
	while(n2->pz != NULL && n2->pz->col == 'R')
	{
	//	printf("\nWhile");
		if(n2->pz == n2->pz->pz->llink)
		{
	//		printf("\nif");
			uncle = n2->pz->pz->rlink; // y is uncle of n2 or sibling of its parent
	//		printf("\nif 11");
			if( uncle != NULL  && uncle->col == 'R')
			{
	//			printf("\nif 111");
				
				n2->pz->pz->col='R';
	//				printf("\nif 1111");
				n2->pz->col='B';
	//				printf("\nif 11111");
				uncle->col='B';
	//				printf("\nif 111111");
				n2=n2->pz->pz;
			}	
			else 
			{
	//			printf("\nif 112");
			
				if( n2 == n2->pz->rlink)
				{
					n2=n2->pz;
					BST_Rotate_Left(n2);
				}
				n2->pz->pz->col='R';
				n2->pz->col='B';
				BST_Rotate_Right(n2->pz->pz);
			}
		}
		else
		{
			//printf("else");
			uncle = n2->pz->pz->llink;
	//		printf(" uncle = %d\n\n\n",uncle);
	//		printf("else22"); // y is uncle of n2 or sibling of its parent
			if( uncle != NULL  && uncle->col == 'R')
			{
			//	printf("if1_else");
				n2->pz->pz->col='R';
				n2->pz->col='B';
				uncle->col='B';
				n2=n2->pz->pz;
			}	
			else 
			{
			//	printf("if_else");
				if(n2 == n2->pz->llink)
				{
					n2=n2->pz;
					BST_Rotate_Right(n2);
				}
				n2->pz->pz->col='R';
				n2->pz->col='B';
				BST_Rotate_Left(n2->pz->pz);
			}	
		}	
	}	
	head->col = 'B';	
}

struct node BST_Rotate_Left(struct node *n1)
{
	//	printf("Rotate Left");	
	struct node* y;
	if(n1->rlink != NULL)
	{
		
	//	printf("\n\n\t\t*\t\t address of n1 : %d",n1);
	//	printf("\n\n\t\t*\t\t address of n1 - > rlink : %d",n1->rlink);
		y = n1->rlink;
	//	printf("\n\n\t\t*\t\t address of y : %d",y);
	//	printf("\n\n\t\t*\t\t address of n1 - > llink : %d",n1->llink);
		n1->rlink = y->llink;
		
	//	printf("\n\n\t\t*\t\t address of y->llink : %d",y->llink);
	//	printf("\n\n\t\t*\t\t address of n1 - > rlink : %d",n1->rlink);
		if(y->llink != NULL)
		{
			y->llink->pz = n1;
			
		}
	//	printf("\n\n\t\t*\t\t address of n1 - > pz : %d",n1->pz);
		y->pz = n1->pz;
	//	printf("\n\n\t\t*\t\t address of y : %d",y);
	//	printf("\n\n\t\t*\t\t address of y - > pz : %d",y->pz);
		if(n1->pz == NULL)
		{
	//		printf("\n\n\t\t*\t\t address of head : %d",head);
	//		printf("\n\n\t\t*\t\t address of y : %d",y);
			head = y;
	//		printf("\n\n\t\t*\t\t address of head after changing  : %d",head);
		}
		else if(n1->pz->llink == n1)
		{
			n1->pz->llink = y;
		}
		else
		{
			n1->pz->rlink = y;
		}
	//	printf("\n\n\t\t*\t\t address of n1 : %d",n1);
		y->llink = n1;
	//	printf("\n\n\t\t*\t\t address of y - > llink : %d",y->llink);
	//	printf("\n\n\t\t*\t\t address of y : %d",y);
		n1->pz = y;
	//	printf("\n\n\t\t*\t\t address of n1->pz : %d",n1->pz);
	}
}

struct node BST_Rotate_Right(struct node *n1)
{	
	struct node* x;
	if(n1->llink != NULL)
	{
		x = n1->llink;
		n1->llink = x->rlink;
		if(x->rlink != NULL)
		{
			x->rlink->pz = n1;
		}
		x->pz = n1->pz;
		if(n1->pz == NULL)
		{
			head = x;
		}
		else if(n1->pz->llink == n1)
		{
			n1->pz->llink = x;
		}
		else
		{
			n1->pz->rlink = x;
		}
		x->rlink = n1;
		n1->pz = x;
	}
}


int main()
{
	int value,choice,option;
	struct node *n1,*p,*root;
	
	printf("\n\n\n\t\t\t\t\t-:\t\tRB Tree\t\t:-\n\n");
	printf("\n\n\t\t*\t\tEnter The data (Integer) : ");
	n1 = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&n1->data);
	n1->col = 'B';
	n1->pz = NULL;
	head = n1;
	n1->rlink = NULL;
	n1->llink = NULL;
	
	printf("\n\n\t\t*\t\tDo You Want More Data (for Yes 1/ for No 0) : ");
	scanf("%d",&choice);
	while(choice==1)
	{
		printf("\n\n\t\t*\t\tEnter The data (Integer): ");
		scanf("%d",&value);
		if(value >head->data)
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
	printf("\n\n\t\t*\t\tDo You Want To Proceed Further(1 for Yes/ 0 For No) :");
	printf("\n\n\t\t*\t\tEnter Your Choice : ");
	scanf("%d",&choice);
	while(choice==1 && head!=NULL)
	{	
		if(head != NULL)
		{
			printf("\n\n\t\t*\t\tChoose Your Choice               -:: ");
			printf("\n\n\t\t*\t\tFor Inserting a Value Press      -:: 1");
			printf("\n\n\t\t*\t\tFor Pre ORDER Traverse Press     -:: 2\n\n\t\t*\t\tFor IN ORDER Traverse Press     -:: 3\n\n\t\t*\t\tFor Post ORDER Traverse Press    -:: 4");
			printf("\n\n\t\t*\t\tFor The Value Of Root Node Prsee -:: 5\n\n\t\t*\t\t Enter Your Choice               -:: ");
			scanf("%d",&option);
			switch(option)
			{
				case 1: 
						printf("\n\n\t\t*\t\tEnter The data (Integer) : ");
						scanf("%d",&value);
						if(value>head->data)
						{
							Create_Right_Sub_tree(head,value);
						}
						else
						{
							Create_Left_Sub_tree(head,value);
						}
						break;
				case 2:
						Pre_Order_Traversal(head);
						printf("\n\n\t\t*\t\tR is Red & B is Black ");
						break;
				case 3:
						In_Order_Traversal(head);
						printf("\n\n\t\t*\t\tR is Red & B is Black ");
						break;
				case 4:
						Post_Order_Traversal(head);
						printf("\n\n\t\t*\t\tR is Red & B is Black ");
						break;
				case 5 : 
						printf("\n\n\t\t*\t\tThe value Of root Node is  : %d",head->data);
						break;
				default : 
					printf("\n\n\t\t*\t\t********* Sorry You Entered A Wrong Choice ******");
					break;		
			}
		}
		else
		{
			printf("\n\n\t\t*\t\t********\t Sorry Tree Is Not Exixt \t*********\n"); 
		}
		printf("\n\n\t\t*\t\tDo You Want To Proceed Further(1 for Yes/ 0 For No) :");
		printf("\n\n\t\t*\t\tEnter Your Choice : ");
		scanf("%d",&choice);
	}
		
	printf("\n\n\n\n\n\t\t\t\t\t********  Practce Makes A Man Success  *********");
	printf("\n\n\n\n");
	return 0;
}

