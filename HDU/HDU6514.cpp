#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int Map[10000010];
int Sum[10000010];

int n, m;

inline int traf(int y, int x)
{
    if(y>n||x>m||y<1||x<1)
        return 0;
    return (y-1)*m+x;
}

inline void cnt()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            Map[traf(i, j)] += Map[traf(i-1, j)]+Map[traf(i, j-1)]-Map[traf(i-1, j-1)];       
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(Map[traf(i, j)] > 1)
                Map[traf(i, j)] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            Map[traf(i, j)] += Map[traf(i-1, j)]+Map[traf(i, j-1)]-Map[traf(i-1, j-1)];       
}

int main ()
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, q;
    int x1, x2, y1, y2;
    while(cin >> n >> m)
    {
        memset(Map, 0, sizeof(Map));
        cin >> p;
        for(int i = 0; i < p; ++i)
        {
            cin >> y1>> x1>> y2>> x2;
            ++Map[traf(y1, x1)];
            if(traf(y2+1, x2+1))
                ++Map[traf(y2+1, x2+1)];
            if(traf(y1, x2+1))
                --Map[traf(y1, x2+1)];
            if(traf(y2+1, x1))
                --Map[traf(y2+1, x1)];
        }
        cnt();

        cin >> q;
        int flag = 1;
        for(int i = 0; i < q; ++i)
        {
            cin >> y1>> x1>> y2>> x2;
            int tn = y2-y1+1;
            int tm = x2-x1+1;
            int ans = Map[traf(y2, x2)];
            if(traf(y2, x1-1))
                ans -= Map[traf(y2, x1-1)];
            if(traf(y1-1, x2))
                ans -= Map[traf(y1-1, x2)];
            if(traf(y1-1, x2-1))
                ans += Map[traf(y1-1, x1-1)];
            if(ans != tn*tm)
                cout <<"NO"<<endl;
            else
                cout <<"YES"<<endl;
        }
    }
    
    return 0;
}