#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int  data;
	struct node *link;	
}*head=NULL;
void create()
{
	struct node *n1,*n2;
	int option;
	n1=(struct node*)malloc(sizeof(struct node));
	printf("\n\tEnter The Data : ");
	scanf("%d",&n1->data);
	n1->link=n1;
	head=n1;
	printf("\n\tDo You want  to Enter More Data (for Yes press 1):  ");
	scanf("%d",&option);
	if(option==1)
	{
		while(option==1)
		{
			n2=(struct node*)malloc(sizeof(struct node));
	    	printf("\n\tEnter The Data : ");
			scanf("%d",&n2->data);
			n1->link=n2;
			n2->link=head;
			n1=n2;
			printf("\n\tDo You want to Enter More Data (for Yes press 1) :  ");
			scanf("%d",&option);
		}
	}
	//else
	//{
	//	printf("\nSorry List Is Not Created*****");
	//}
}
void travers()
{
	struct node *temp;
	if(head!=NULL)
	{  
	    temp=head;
		while(temp->link!=head)
		{
			printf("\n\tData is : %d ",temp->data);
			temp=temp->link;
		}
		printf("\n\tData is : %d ",temp->data);
	}
	else
	{
		printf("\n\tSorry List is Empty***********");
	}
}
void insert_front()
{
	struct node *new1,*temp;
	new1=(struct node*)malloc(sizeof(struct node));
	printf("\n\tEnter Data : ");
	scanf("%d",&new1->data);
	temp=head;
	while(temp->link!=head)
		{
			temp=temp->link;
		}
	new1->link=head;
	head=new1;
	temp->link=head;
}
void insert_mid()
{
	int position;
	struct node *new1,*temp,*p;
	printf("\n\tEnter The postion Where You Want To Insert The Node : ");
	scanf("%d",&position);
	new1=(struct node*)malloc(sizeof(struct node));
    printf("\n\tEnter Data : ");
	scanf("%d",&new1->data);
	if(head!=NULL)
	{    
		temp=head;
		
		while(position!=1)
		{	
			p=temp;
			temp=temp->link;
			position--;
		}
		p->link=new1;
		new1->link=temp;
	}
	else
	{
		printf("\n\tList Is Not Created ");
	}
}
void insert_last()
{
	struct node *new1,*temp;
	new1=(struct node*)malloc(sizeof(struct node));
    printf("\n\tEnter Data : ");
	scanf("%d",&new1->data);
	if(head!=NULL)
	{
		temp=head;
		while(temp->link!=head)
		{
			temp=temp->link;
		}
		temp->link=new1;
		new1->link=head;
	}
	else
	{
		printf("\n\tSorry List Is not created ******** ");
	}
}
void delete_front()
{
	struct node *temp,*n1;
	n1=head;
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	head=head->link;
	temp->link=head;
	free(n1);
}
void delete_middle()
{
	int position;
	struct node *temp,*p;
	printf("\n\tEnter The postion Where You Want To Delete The Node : ");
	scanf("%d",&position);
	if(head!=NULL)
	{    
		temp=head;
		while(position!=1)
		{	
			p=temp;
			temp=temp->link;
			position--;
		}
		p->link=temp->link;
		free(temp);
	}	
}
void delete_last()
{	
	struct node *temp;
	temp=head;
	while(temp->link->link!=head)
	{
		temp=temp->link;
	}
	free(temp->link);
	temp->link=head;
}
int main()
{   
 	printf("\n \t\t\t\t\t -|  CERCULER LINK LIST  |-\n ");
	create();
	int option,choice;
	printf("\n\tDo You Want To Proceed Further (for yes press 1): ");
	scanf("%d",&option);
	if(option==1)
	{
		while(option==1)
		{
			printf("\n\tfor create New list press : 1\n\tfor traverse press        : 2\n\tfor insert in Front press   : 3\n\tfor insert in Middle press :4 ");
			printf("\n\tfor Insert is last press  : 5\n\tfor Delete in Front press :6\n\tfor Delete in middle press  : 7\n\tfor Delete in Last press : 8\n");
			printf("\n\n\tEnter Choice  : ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: create();
				break;
				case 2: travers();
				break;
				case 3: insert_front();
				break;
				case 4: insert_mid();
				break;
				case 5: insert_last();
				break;
				case 6: delete_front();
				break;
				case 7: delete_middle();
				break;
				case 8: delete_last();
				break;
			}
			printf("\n\n\tDo You Want To Proceed Further (for Yes press 1): ");
			scanf("%d",&option);
		
		}
	}
}
