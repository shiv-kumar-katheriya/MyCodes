#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int a[200],int n)
{
	int i,j,temp; 
	for(i=1;i<n;i++)
	{
		temp = a[i];
		j = i-1;
		while(j >= 0 && temp < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}

}

int main()
{
	printf("\n\n\t\t-: Insertion Sort :-");
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
	
	insertion_sort(a,size);
	printf("\n\n\tElement You Entered After sorting : ");
	
	for(i=0; i<size; i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

