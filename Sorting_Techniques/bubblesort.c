// Bubble Sort

#include<stdio.h>
#define MAX 1000

void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void bubbleSort(int arr[], int range)
{
	int i, j;
	for(i = 0; i < (range-1); i++)
		for(j = 0; j < (range- i-1); j++)
			if(arr[j] > arr[j + 1])
				swap(&arr[j],&arr[j + 1]);
}

main()
{
	int i, range, arr[MAX];
	printf("\n Enter range: ");
	scanf("%d",&range);
	
	printf("\n Enter elements: ");
	for(i = 0; i < range; i++)
		scanf("%d",&arr[i]);
	
	bubbleSort(arr, range);
	printf("\n After Sorting: ");
	for(i = 0; i < range; i++)
		printf("%d\t", arr[i]);
}
