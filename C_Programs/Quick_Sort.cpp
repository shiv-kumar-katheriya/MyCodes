#include<stdio.h>
#include<stdlib.h>
int size,q;

int Partition(int a[200],int p,int r)
{		
 int i;
/* printf("\n\nElement in the partition function when P = %d |||  R = %d\t\t\t::",p,r);
 
	for(i=0; i<size; i++)
	{
		printf(" %d",a[i]);
	}
*/
 int temp,swap,k;
	temp = a[r];
	k = p-1;
	for(i=p ; i<r ; i++)
	{ 
		if(a[i] > temp)
		{
			k = k + 1 ;
			swap = a[k];
			a[k] = a[i];
			a[i] = swap;
		}
	}
	swap = a[k+1];
	a[k+1] = temp;
	a[r] = swap;
	return k+1;
}
void Quick_Sort(int a[200],int p, int r)
{
	int i;
/*	printf("\n\nElement in the Quick Sort function when P = %d |||  R = %d\t\t\t::",p,r);
 	
	for(i=0; i<size; i++)
	{
		printf(" %d",a[i]);
	}
*/	
	if(p<r)
	{
		q = Partition(a,p,r);
		Quick_Sort(a,p,q-1);
		Quick_Sort(a,q+1,r);
	}
}

int main()
{
	printf("\n\n\t\t-: Quick Sort :-");
	int i,j,key,a[200];
	printf("\n\n\t Enter The Size of the Array : ");
	scanf("%d",&size);
	printf("\n\n\tEnter The %d Elements : ",size);
	
	for(i=0; i<size; i++)
	{
		printf("\t");
		scanf("%d",&a[i]);
	}
	
	printf("\n\n\tElement You Entered Before Sorting : ");
	for(i = 0; i<size; i++)
	{
		printf(" %d",a[i]);
	}
	
	Quick_Sort(a,0,size-1);
	printf("\n\n\tElement You Entered After Sorting : ");
	
	for(i=size-1; i>=0; i--)
	{
		printf(" %d",a[i]);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

