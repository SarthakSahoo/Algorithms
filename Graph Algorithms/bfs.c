//Aim: C Program to implement BFS for a Connected Graph

#include<stdio.h>
#include<limits.h>
#define MAX 100
int nv;

struct vertex
{
	char color;
	int d, pi;
}v[MAX];

int rear = -1, front = -1;
int LQ[MAX];
void print_path(int [][MAX],int ,int);
void ENQUEUE(int);
int DEQUEUE();
void BFS(int [][MAX], int);

main()
{
	int G[MAX][MAX], i, j, source, destination;

	printf("\n Enter number of vertex:");
	scanf("%d", &nv);

	for(i = 0; i < nv; i++)
	{
		for(j = 0; j < nv; j++)
		{
			printf("\n Is there is a edge between %d -> %d:", i ,j);
			scanf("%d",&G[i][j]);
		}
	}

	printf("\n Enter the Source Vertex: ");
	scanf("%d", &source);

	BFS(G, source);

	for(i = 0; i < nv; i++)
		printf("%d = %d\n",i, v[i].pi);

	printf("\n Enter destination vertex:");
	scanf("%d", &destination);
	print_path(G, source, destination);
	printf("\n");

}

void print_path(int G[][MAX],int source, int destination)
{
	if(source == destination)
		printf("%d", source);
	else if(v[destination].pi == -1)
	{
		printf("\n NO PATH EXISTS\n");
	}
	else
	{
		print_path(G,source, v[destination].pi);
		printf("->%d", destination);
	}
}

void BFS(int G[][MAX], int source)
{
	int i, j, u;

	for(i = 0; i < nv; i++)
	{
		if(i == source)
			continue;
		v[i].color = 'w';
		v[i].d = INT_MAX;
		v[i].pi = -1;
	}

	v[source].color = 'g';
	v[source].d = 0;
	v[source].pi = -1;
	ENQUEUE(source);

	while(front != -1)
	{
		u = DEQUEUE();
		for(j = 0; j < nv; j++)
		{
			if(G[u][j] != 0 && v[j].color == 'w')
			{
				v[j].color = 'g';
				v[j].d = v[u].d + 1;
				v[j].pi = u;
				ENQUEUE(j);
			}
			v[u].color = 'b';
		}
	}
}

void ENQUEUE(int item)
{
	if(front == MAX - 1)
	{
		printf("\n OVERFLOW\n");
		return;
	}

	else if(front == -1 && rear == -1)
	{
		front++;
		rear++;
		LQ[front] = item;
	}

	else
	{
		front++;
		LQ[front] = item;
	}
}

int  DEQUEUE()
{
	int temp;

	if(front == -1 && rear == -1)
	{
		printf("\nUnderflow\n");
		return;
	}

	else if(rear == front)
	{
		temp = LQ[rear];
		rear = -1;
		front = -1;
		return temp;
	}

	temp = LQ[rear];
	rear += 1;
	return temp;
}
