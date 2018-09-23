// Quick Sort

#include<stdio.h>
#define MAX 1000

void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

int partition(int arr[], int lb, int ub)
{
	int i, j, x;
	x = arr[ub];
	i = lb - 1;
	for(j = lb; j < ub; j++)
	{
		if(arr[j] <= x)
		{
			i+=1;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1],&arr[ub]);
	return (i + 1);
}

void quickSort(int arr[], int lb, int ub)
{
	if(lb < ub)
	{
		int point = partition(arr, lb, ub);
		quickSort(arr, lb, point - 1);
		quickSort(arr, point + 1, ub);
	}
}

main()
{
	int i, range, arr[MAX];
	
	printf("\n Enter range: ");
	scanf("%d", &range);
	
	printf("\n Enter elements: \n");
	for(i = 0; i < range; i++)
		scanf("%d",&arr[i]);
		
	quickSort(arr, 0, range - 1);
	
	printf("\n After Sorting: ");
	for(i = 0; i < range; i++)
		printf("%d\t",arr[i]);
}
