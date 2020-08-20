#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 260
#define bigInt 100000
int bigLand[MAXN][MAXN];

void work(int x,int y,int B)
{
	int i,j;
	int max=-1;
	int min=bigInt;
	for (i=x;i<=x+B-1;i++)
	{
		for(j=y;j<=y+B-1;j++)
		{
			if (bigLand[i][j]>max)
				max=bigLand[i][j];

			if(bigLand[i][j]<min)
				min=bigLand[i][j];
		}
	}
	printf("%d\n", max-min);
}

int main()
{
	int N,B,K; 
	int x,y; 
	while(scanf("%d%d%d", &N, &B, &K)!=EOF)
	{
		for (int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				scanf("%d",&bigLand[i][j]);
		for(int i=0;i<K;i++)
		{
			scanf("%d%d", &x, &y);
			work(x,y,B); 
		}
	}
	return 0;
}