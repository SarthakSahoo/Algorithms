// Selection Sort

#include<stdio.h>
#define MAX 1000

void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void selectionSort(int arr[], int range)
{
	int i, j, index;
	for(i = 0; i < range-1; i++)
	{
		index = i;
		for(j = i + 1; j < range; j++)
			if(arr[j] < arr[index])
				index = j;
				
		swap(&arr[index],&arr[i]); 
	}
}

main()
{
	int i, range, arr[MAX];
	
	printf("\n Enter range: ");
	scanf("%d",&range);
	
	printf("\n Enter elements: ");
	for(i = 0; i < range; i++)
		scanf("%d",&arr[i]);
		
	selectionSort(arr, range);
	
	printf("\n After Sorting: ");
	for(i = 0; i < range; i++)
		printf("%d\t", arr[i]);
}
