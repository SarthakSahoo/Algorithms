// Binary Search

#include<stdio.h>
#define MAX 1000

void binarysearch(int array[], int lb, int ub, int number)
{
	int mid;
	if(lb > ub)
	{
		printf("\n Number not Found\n");
		return;
	}
	mid = (lb + ub) / 2;
	if(array[mid] == number)
		printf("\n Number Found\n");
	else if(array[mid] < number)
		binarysearch(array, mid + 1, ub, number);
	else
		binarysearch(array, lb, mid - 1, number);
}

main()
{
	int index, range, array[MAX], number, lb, mid, ub;
	
	printf("\nEnter Range: ");
	scanf("%d", &range);
	
	printf("\n Enter elements: \n");
	for(index = 0; index < range; index++)
		scanf("%d",&array[index]);
	
	printf("\n Enter number to find: ");
	scanf("%d",&number);
	
	binarysearch(array, 0, range, number);
}
