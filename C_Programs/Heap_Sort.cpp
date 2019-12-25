#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Heap_Size;
void Heap_Sort(int a[200]);
Max_Heapify(int a[200],int i)
{
	int left,right,largest,Swap;
	
	left  =  i * 2 + 1 ;
	right =  i * 2 + 2 ;
	
	if ( left < Heap_Size && a[left] > a[i] )
	{
		largest = left ;	
	}
	else
	{
		largest = i;	
	}
	
	if( right < Heap_Size && a[right] > a[largest] )
	{
		largest = right ;	
	}
	
	if( largest != i)
	{
		Swap = a[largest];
		a[largest] = a[i];
		a[i] = Swap;
		Max_Heapify(a,largest);
	}
	
}

Build_Max_Heap(int a[200])
{
	int i;
	for(i = ( Heap_Size/2 ) - 1 ; i >= 0; i--)
	{
		Max_Heapify(a,i);
	}
}

void Heap_Sort(int a[200])
{	
	int i,Swap,j;
	Build_Max_Heap(a);
	/*
	printf("\n\nAfter First Build Maxheap function : ");
	for(i=0; i<Heap_Size; i++)
	{
		printf(" %d",a[i]);
	}
	*/
	j = Heap_Size;
	for( i = Heap_Size-1 ; i > 0 ; i--)
	{
		Swap = a[0] ;
		a[0] = a[Heap_Size-1] ;
		a[Heap_Size-1] = Swap ;
		Heap_Size = Heap_Size-1 ;
		/*
		printf("\n\nAfter Swapping Array Becomes : ");
		for(i=0; i<Heap_Size; i++)
		{
			printf(" %d",a[i]);
		}
		*/
			
		Max_Heapify(a,0);	
	}
}

int main()
{
	printf("\n\n\t\t-: \tHeap Sort\t :-");
	int i,j,key,a[200];
	printf("\n\n\t Enter The size of the array : ");
	scanf("%d",&Heap_Size);
	printf("\n\n\tEnter The %d elements : ",Heap_Size);
	
	for(i=0; i<Heap_Size; i++)
	{
		printf("\t");
		scanf("%d",&a[i]);
	}
	
	printf("\n\n\tElement You Entered before sorting : ");
	for(i = 0; i<Heap_Size; i++)
	{
		printf(" %d",a[i]);
	}
	j = Heap_Size;
	Heap_Sort(a);
	printf("\n\n\tElement You Entered After sorting : ");
	
	for(i=0; i<j; i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

