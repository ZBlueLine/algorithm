
#include <bits/stdc++.h>

using namespace std;

int a[210],n,flag[210];

void BFS(int s,int t)
{
   int v;
   queue<int> q;
   q.push(s);
   flag[s]=1;
   while(!q.empty())
   {
       v=q.front();
       q.pop();
       if(v==t)
         break;
       if(v+a[v]<=n&&flag[v+a[v]]==0)
       {
          q.push(v+a[v]);
          flag[v+a[v]]=flag[v]+1;
       } 
       
       if(v-a[v]>=1&&flag[v-a[v]]==0)
       {
          q.push(v-a[v]);
          flag[v-a[v]]=flag[v]+1;
       }
   }
   if(v!=t)
     flag[t]=0;
   
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,s,t;
    while(cin>> n>> s>> t&&n)
    {
       for(i=1;i<=n;i++)
          cin >> a[i];
       memset(flag,0,sizeof(flag));
       BFS(s,t);
       cout<<flag[t]-1<<endl;
    }
    return 0;
}