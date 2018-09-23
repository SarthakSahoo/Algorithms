//C program to implement merge sort

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 30

void mergesort(int [], int , int);
void merge(int [], int , int , int);


main()
{
	int  range, index, arr[MAX];
	printf("\n Enter range:");
	scanf("%d", &range);
	
	printf("\n Enter the element :");
	for(index = 0; index < range; index++)
		scanf("%d",&arr[index]);
		
	printf("\n The elements before sorting:");
	for(index = 0; index < range; index++)
		printf("%d\t", arr[index]);
		
	mergesort(arr, 0, range-1);
	
	printf("\n The elements after sorting:");
	for(index = 0; index < range; index++)
		printf("%d\t", arr[index]);
}


void merge(int arr[],int lb, int mid, int ub)
{
	int n1, n2, i, j, k, arr1[MAX], arr2[MAX];
	n1 = mid - lb + 1;
	n2 = ub - mid;
	
	
	for(i = 0; i < n1; i++)
		arr1[i] = arr[lb + i];
		
		
	for(j = 0; j < n2; j++)
		arr2[j] = arr[mid + j +1];
		
		
	arr1[n1] = INT_MAX;
	arr2[n2] = INT_MAX;
	
	
	i = 0;
	j = 0;
	
	for(k = lb; k <= ub; k++)
	{
		if(arr1[i] < arr2[j])
		{
			arr[k] = arr1[i];
			i+=1;
		}
		else
		{
			arr[k] = arr2[j];
			j+=1;
		}
	}
}


void mergesort(int arr[], int lb, int ub)
{
	int mid;
	if(lb < ub)
	{
		mid = (lb + ub) / 2;
		mergesort(arr, lb, mid);
		mergesort(arr, mid+1, ub);
		merge(arr, lb, mid, ub);
	}
}
