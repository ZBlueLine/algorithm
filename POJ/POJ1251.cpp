#include <iostream>
#include <algorithm>

using namespace std;

struct Edge{
    int b, e;
    int v;
} edge[80];

bool cmp(Edge a, Edge b)
{return a.v < b.v;}

int father[40];

inline void init()
{
    for(int i = 0; i < 31; ++i)
        father[i] = i;
}

int Find(int a)
{
    if(father[a] != a)
        return father[a] = Find(father[a]);
    return a;
}

int kruskal(int cnt)
{
    int sum = 0;
    sort(edge, edge+cnt, cmp);
    for(int i = 0; i < cnt; ++i)
    {
        int fa, fb;
        fa = Find(edge[i].b);
        fb = Find(edge[i].e);
        if(fa == fb)continue;
        sum += edge[i].v;
        father[fa] = fb;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n&&n)
    {
        init();
        int cnt = 0;
        for(int i = 0; i < n-1; ++i)
        {
            int num;
            int v;
            string s, e;
            cin >> s;
            cin >> num;
            while(num--)
            {
                cin >> e;
                cin >> v;
                edge[cnt].b = s[0]-'A';
                edge[cnt].e = e[0]-'A';
                edge[cnt++].v = v;
            }
        }
        cout<<kruskal(cnt)<<endl;
    }
    return 0;
}