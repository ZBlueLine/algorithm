
#include<stdio.h>
#include<algorithm>
#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;
struct path
{
    int x,y;
    double w;
}a[500*500+50];
int x[505];
int y[505];
double ans[505];
int f[505];
double dis(int i,int j)
{
    double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    return d;
}
double cmp(path a,path b)
{
    return a.w<b.w;
}
int find(int x)
{
    int r=x;
    while(f[r]!=r)
    {
        r=f[r];
    }
    return r;
}
void merge(int x,int y)
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
    {
        f[xx]=yy;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int s,n;
        scanf("%d%d",&s,&n);
        for(int i=0;i<n;i++)f[i]=i;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        int cont=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                a[cont].x=i;
                a[cont].y=j;
                a[cont++].w=dis(i,j);
            }
        }
        int cont2=0;
        sort(a,a+cont,cmp);
        for(int i=0;i<cont;i++)
        {
            if(find(a[i].x)!=find(a[i].y))
            {
                ans[cont2++]=a[i].w;
                merge(a[i].x,a[i].y);
            }
        }
        printf("%.2f\n",ans[cont2-s]);
    }
}