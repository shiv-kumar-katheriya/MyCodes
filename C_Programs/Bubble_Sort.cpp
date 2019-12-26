#include<stdio.h>
#include<stdlib.h>

void Bubble_Sort(int a[200],int n)
{
	int i,j,temp;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
int main()
{
	printf("\n\n\t\t-: Bubble Sort :-");
	int i,j,size,key,a[200];
	printf("\n\n\t Enter The size of the array : ");
	scanf("%d",&size);
	printf("\n\n\tEnter The %d elements : ",size);
	
	for(i=0; i<size; i++)
	{
		printf("\t");
		scanf("%d",&a[i]);
	}
	
	printf("\n\n\tElement You Entered before sorting : ");
	for(i = 0; i<size; i++)
	{
		printf(" %d",a[i]);
	}
	
	Bubble_Sort(a,size);
	
	printf("\n\n\tElement You Entered After sorting : ");
	
	for(i=0; i<size; i++)
	{
		printf(" %d",a[i]);
	}

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

