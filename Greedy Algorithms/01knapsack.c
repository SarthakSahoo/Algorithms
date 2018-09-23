//Aim: Program to Implement 0/1 knapsack Problem


#include<stdio.h>
#define MAX 100
int a[MAX][MAX], b[MAX][MAX], w[MAX], v[MAX], W, n;

void calculate_profit();
void print_selected_items(int , int);


main()
{
	int i;
	printf("\n Enter the number of items:");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		printf("\n Enter the weight and value of item%d:",(i + 1));
		scanf("%d %d", &w[i], &v[i]);
	}

	/*printf("\n Enter the weights of the items:");
	for(i = 0; i < n; i++)
		scanf("%d",&w[i]);

	printf("\n Enter the values of the items:");
	for(i = 0; i < n; i++)
		scanf("%d",&v[i]);*/

	printf("\n Enter the maximum capacity of knapsack:");
	scanf("%d", &W);

	calculate_profit();
	print_selected_items(n, W);

	printf("\n Maximum Profit: %d\n", a[n][W]);
}


void  calculate_profit()
{
	int i,j;
	for(i = 0; i <= W; i++)
		a[0][i] = 0;

	for(i = 1; i <=n; i++)
		a[i][0] = 0;

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= W; j++)
		{
			if(w[i - 1] <= j)
			{
				if(v[i - 1] + a[i - 1][j - w[i - 1]] > a[i - 1][j])
				{
					a[i][j] = v[i - 1] + a[i - 1][j - w[ i - 1]];
					b[i][j] = 1;
				}
				else
				{
					a[i][j] = a[i - 1][j];
					b[i][j] = 0;
				}

			}
			else
			{
				a[i][j] = a[i - 1][j];
				b[i][j] = 0;
			}
		}
	}
}

void print_selected_items(int i , int j)
{
	if(i == 0 || j == 0)
		return;

	else if(b[i][j] == 1)
	{
		print_selected_items(i - 1, j - w[i - 1]);
		printf("Item: %d\n",i);
	}
	
	else
		print_selected_items(i - 1, j);
	
}
