//Aim: C program to implement matrix chain multiplication problem

#include<stdio.h>
#include<limits.h>
#define MAX 100
int p[MAX],n, m[MAX][MAX],s[MAX][MAX];

void print_optimal_parens(int i , int j)
{
	if(i == j)
		printf("A%d",i);

	else
	{
		printf("(");
		print_optimal_parens(i, s[i][j]);
		print_optimal_parens(s[i][j] + 1, j);
		printf(")");
	}

}

void matrix_chain_order(int p[], int size)
{
	int n1, i, j, l,q, k;
	n1 = size - 1;

	for(i = 0; i <= n1; i++)
		m[i][i] = 0;

	for(l = 2; l <= n1; l++)
	{
		for(i = 1; i <= (n1 - l + 1); i++)
		{
			j = i + l -1;
			m[i][j]= INT_MAX;
			
			for(k = i; k < j; k++)
			{
				q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
				if(m[i][j] > q)
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

main()
{
	int index;
	printf("\n Enter the number of matrix:");
	scanf("%d",&n);
	
	printf("\n Enter the dimensions of the matrices:");
	for(index = 0; index <= n; index++)
		scanf("%d",&p[index]);

	matrix_chain_order(p, n + 1);

	printf("\n Answer is:");
	print_optimal_parens(1,n);

}
