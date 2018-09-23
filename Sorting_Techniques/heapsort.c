//C Program to implement heapsort using MAX_HEAPIFY algorithm

#include<stdio.h>
#define MAX 100

int arr[MAX], hsize, n;
void input()
{
	int index;
	for(index = 0; index < n; index++)
		scanf("%d", &arr[index]);
	
}

void display_sorting()
{
	int index;
	for(index = 0; index < n; index++)
		printf("%d\t", arr[index]);
	
}


void swap(int *i, int *j)
{
	*i = *i + *j;
	*j = *i - *j;
	*i = *i - *j;
}

int left(int i)
{
	return ((2 * i) +1);
}

int right(int i)
{
	return ((2 * i) + 2);
}

void max_heapify(int i)
{
	int l, r, temp, largest;
	
	l = left(i);
	r = right(i);
	
	if((l < hsize) && (arr[l] > arr[i]))
		largest = l;
		
	else
		largest = i;
		
	if((r < hsize) && (arr[r] > arr[largest]))
		largest = r;
		
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		max_heapify(largest);
	}
}

void build_maxheap()
{
	hsize = n;
	int i;
	for(i = (n - 2) /2; i >= 0; i--)
		max_heapify(i);
}

void heapsort()
{
	build_maxheap();
	int i, temp;
	
	for(i = n - 1 ; i >= 1 ; i--)
	{
		swap(&arr[i], &arr[0]);
		hsize-=1;
		max_heapify(0);
	}
}

main()
{
	int index;
	
	printf("\n Enter range: ");
	scanf("%d", &n);
	
	printf("\n Enter elements: \n");
	input();
	heapsort();
	
	printf("\n Elements After Sorting: ");
	display_sorting();
}
