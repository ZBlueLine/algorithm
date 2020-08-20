#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;

struct sphere{
    double x, y, z;
    double r;
};

sphere Sp[100];
double Map[100][100];
bool vis[100];

double cntdist(int s1, int s2)
{
    sphere a,b;
    a = Sp[s1];
    b = Sp[s2];
    double dist = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
    double sumr = (a.r+b.r)*(a.r+b.r);
    if(dist<=sumr)
        return 0.0;
    return sqrt(dist)-sqrt(sumr);
}
struct edge{
    int aim;
    double dist;
};

struct cmp{
    bool operator() (edge a, edge b)
    {
        return a.dist > b.dist;
    }
};

double prim(int point, int beg)
{
    priority_queue<edge, vector<edge>, cmp> q;
    double ans = 0;
     for(int i = 0; i < point; ++i)
     {
         edge temp;
         temp.aim = i;
         temp.dist = Map[beg][i];
         if(!vis[i])
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
            for(int i = 1; i < point; ++i)
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
    int n;
    while(cin >> n&&n)
    {
        memset(vis, false, sizeof(vis));
        int cnt = -1;
        for(int i = 0; i < n; ++i)
            cin >> Sp[++cnt].x>>Sp[cnt].y>>Sp[cnt].z>>Sp[cnt].r;
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                Map[i][j] = Map[j][i] = cntdist(i, j);
        int beg = 0;
        for(int i = 0; i < n; ++i)
            if(vis[i]==true)
            {
                beg = i;
                break;
            }
        cout << fixed << setprecision(3) << prim(n, beg)<<endl;
    }
    return 0;
}