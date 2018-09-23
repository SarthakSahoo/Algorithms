//Aim: C program to implement Longest Common Subsequence Problem


#include<stdio.h>
#include<string.h>
#define MAX 50
int c[MAX][MAX], m, n;
char b[MAX][MAX], x[MAX], y[MAX];

void print_lcs(int i, int j)
{
	if(i == 0 || j == 0)
		return;

	if(b[i][j] == 'c')
	{
		print_lcs(i - 1, j - 1);
		printf("%c",x[i - 1]);
	}
	else if(b[i][j] == 'u')
		print_lcs(i - 1, j);

	else
		print_lcs(i, j - 1);
}

void lcs()
{
	int i, j;
	m = strlen(x);
	n = strlen(y);
	
	for(i = 0; i <= m ; i++)
		c[i][0] = 0;
	for(j = 0; j <=n ; j++)
		c[0][j] = 0;

	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'c';
			}

			else if(c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'u';
			}


			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'l';
			}
		}
	}

}

main()
{
	printf("\n Enter 1st sequence:");
	scanf("%s",x);

	printf("\n Enter 2nd sequence:");
	scanf("%s",y);

	printf("\n LCS is:");
	lcs();
	print_lcs(m,n);
	printf("\n");
	printf("\n Length of the LCS is:%d",c[m][n]);
	printf("\n");
}
