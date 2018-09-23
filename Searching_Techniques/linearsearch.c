// Linear Search algorithm

#include<stdio.h>
#define MAX 1000

int main()
{
	int index, range, array[MAX], number, value = 0;
	
	printf("\n Enter Range: ");
	scanf("%d",&range);
	
	printf("\nEnter elements into array: \n");
	for(index = 0; index < range; index++)
		scanf("%d",&array[index]);
		
	printf("\nEnter the element to be searched: ");
	scanf("%d",&number);
	
	for(index = 0; index < range; index++)
	{
		if(array[index] == number)
		{
			printf("Number Found at position: %d\n", (index + 1));
			value = 1;
		}
	}
	if(value == 0)
		printf("Number not found\n");
}
