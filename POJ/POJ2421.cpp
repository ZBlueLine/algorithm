#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;

double Map[1010][1010];
bool vis[1010];

struct edge{
    int aim;
    int dist;
};

struct cmp{
    bool operator() (edge a, edge b)
    {
        return a.dist > b.dist;
    }
};

int prim(int point, int beg)
{
    priority_queue<edge, vector<edge>, cmp> q;
    int ans = 0;
     for(int i = 1; i <= point; ++i)
     {
        edge temp;
        temp.aim = i;
        temp.dist = Map[beg][i];
        q.push(temp);
     }
     while(!q.empty())
     {
        edge newp = q.top();
        q.pop();
        if(!vis[newp.aim])
        {   
            ans += newp.dist;
            vis[newp.aim] = true;
            for(int i = 1; i <= point; ++i)
            {
                edge temp;
                temp.aim = i;
                temp.dist = Map[newp.aim][i];
                if(!vis[i])
                    q.push(temp);
            }
        }
     }
     return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    int T;
    int v[1010];
    cin >> T;
    while(T--)
    {
        cin>>n;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; ++i)
            cin >> v[i];
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                cin >> Map[i][j];
                if(i!=j)Map[i][j] += v[i]+v[j];
            }
        }
        vis[1] = true;
        cout<<prim(n, 1)<<endl;
    }
    
    return 0;
}