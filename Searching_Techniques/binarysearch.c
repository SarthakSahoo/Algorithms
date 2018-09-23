// Binary Search

#include<stdio.h>
#define MAX 1000

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
	
	lb = 0;
	ub = range - 1;
	mid = (lb + ub) / 2;
	
	while(lb <= ub)
	{
		if(array[mid] < number)
			lb = mid + 1;
		else if(array[mid] == number)
		{
			printf("Number found at: %d\n", (mid + 1));
			break;
		}
		else
			ub = mid - 1;
		mid = (lb + ub) / 2;
	}
	if(lb > ub)
		printf("\n Number not found\n");
}
