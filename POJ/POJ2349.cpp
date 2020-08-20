#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;

double Map[2010][2010];
bool vis[2010];

struct P{
    double x, y;
};
P stat[510];
double save[510];
int scnt = -1;
double prim(int point, int beg)
{
    double ans = 0;
    double dist[2010];
    for(int i = 0; i < point; ++i)
        dist[i] = Map[beg][i];
    for(int j = 1; j < point; ++j)
    {
        double Min = 0x3fffffff;
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
        save[++scnt] = Min;
        for(int i = 0; i < point; ++i)
            if(!vis[i])
                dist[i] = min(dist[i], Map[fmin][i]);
    }
    return ans;
}

bool cmp(double a, double b)
{
    return a > b;
}

inline double cntdist(P a, P b)
{
    double ans = 0.0;
    ans = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return sqrt(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int s, p;
    while(T--)
    {
        scnt = -1;
        memset(vis, false, sizeof(vis));
        memset(save, 0, sizeof(save));
        cin >> s>> p;
        for(int i = 0; i < p; ++i)
            cin >> stat[i].x>> stat[i].y;
        for(int i = 0; i < p; ++i)
        {
            for(int j = i; j < p; ++j)
                Map[j][i] = Map[i][j] = cntdist(stat[i], stat[j]);
        }
        vis[0] = true;
        double ans = prim(p, 0);
        sort(save, save+p-1, cmp);
        cout << fixed << setprecision(2) << save[s-1]<<endl;
    }
    return 0;
}