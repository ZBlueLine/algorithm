#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;

int Map[2010][2010];
bool vis[2010];


int prim(int point, int beg)
{
    int ans = 0;
    int dist[2010];
    for(int i = 0; i < point; ++i)
        dist[i] = Map[beg][i];
    int now = 1;
    for(int j = 1; j < point; ++j)
    {
        int Min = 0x3f3f3f;
        int fmin = -1;
        for(int i = 0; i < point; ++i)
        {
            if(!vis[i]&&dist[i]<Min)
            {
                Min = dist[i];
                fmin = i;
            }
        }
        vis[fmin] = true;
        ans += Min;
        for(int i = 0; i < point; ++i)
            if(!vis[i])
                dist[i] = min(dist[i], Map[fmin][i]);
    }
    return ans;
}

char id[2010][8];

int cntc(char a[], char b[])
{
    int ans = 0;
    for(int i = 0; i < 7; ++i)
        if(a[i]!= b[i])++ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(scanf("%d",&n),n)
    {
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < n; ++i)
            scanf("%s",id[i]);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(j == i)Map[i][j] = 0;
                else Map[i][j] = cntc(id[i], id[j]);
            }
        }
        vis[0] = true;
        int ans = prim(n, 0);
        printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}