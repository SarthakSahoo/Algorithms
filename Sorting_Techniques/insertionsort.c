// Insertion Sort

#include<stdio.h>
#define MAX 1000

void insertionSort(int arr[], int range)
{
	int i, j, key;
	for(j = 1; j < range; j++)
	{
		key = arr[j];
		i = j - 1;
		while(i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i-=1;
		}
		arr[i + 1] = key;
	}
}

main()
{
	int i, range, arr[MAX];
	printf("\n Enter Range: ");
	scanf("%d", &range);
	
	printf("\n Enter elements: ");
	for(i =0; i < range; i++)
		scanf("%d",&arr[i]);
	
	insertionSort(arr, range);
	
	printf("\n After Sorting: \t");
	for(i = 0; i < range; i++)
		printf("%d\t", arr[i]);
}
