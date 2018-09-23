//C program to implement fractional knapsack problem

#include<stdio.h>
#define MAX 100

struct item
{
	int id;
	float weight, value;
};

float x[MAX];
struct item a[MAX];
void greedy_knapsack(int , int);
void sort(int);


main()
{
	int n, w, i, j;
	printf("\n Enter the total number of items:");
	scanf("%d",&n);
	
	for(i = 0; i < n; i++)
	{
		a[i].id = (i + 1);
		printf("\n Enter the value and weight of item %d:", (i + 1));
		scanf("%f %f", &a[i].value, &a[i].weight);
	}

	printf("\n Enter the maximum weight of the knapsack:");
	scanf("%d", &w);

	greedy_knapsack(w, n);

	
	printf("item\tvalue\t\tweight\t\tquantity to be taken\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%f\t%f\t%f\n",a[i].id, a[i].value, a[i].weight, x[i]);
	}
}

void greedy_knapsack(int W, int n)
{
	int i ,j , u, t1, t, t2;
	sort(n);

	for(i = 0; i < n; i++)
		x[i] = 0.0;

	u = W;
	for(i = 0; i < n; i++)
	{
		if(a[i].weight > u)
			break;
		x[i] = 1.0;
		u = u - a[i].weight;
	}

	if(i < n)
		x[i] = u / a[i].weight;
}

void sort(int n)
{
	int i, j, t, t1, t2;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if((a[i].value / a[i].weight) > (a[j].value / a[j].weight))
			{
				t = a[i].weight;
				a[i].weight = a[j].weight;
				a[j].weight = t;

				t1 = a[i].value;
				a[i].value = a[j].value;
				a[j].value = t1;

				t2 = a[i].id;
				a[i].id = a[j].id;
				a[j].id = t2;
			}
		}
	}
}

