#include <bits/stdc++.h>

using namespace std;


int father[300];
void init()
{
    for(int i = 0; i <= 210; ++i)
        father[i] = i;
}

int find(int a)
{
    if(father[a] == a)return a;
    return father[a] = find(father[a]);
}
void Union(int a, int b)
{
    if(find(a)==find(b))return;
    father[find(a)] = find(b);
}

struct sars{
    int s;
    int e;
    int p;
};

bool cmp(sars a, sars b)
{
    return a.p < b.p;
}

sars d[1010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int s, e, p;
    while(cin >> n >> m)
    {
        for(int i = 0; i < m; ++i)
            cin >> d[i].s>>d[i].e>>d[i].p;
        sort(d, d+m, cmp);
        int Q;
        int a, b;
        cin >> Q;
        while(Q--)
        {
            int ans = 0x3f3f3f;
            cin >> a >> b;
            for(int i = 0; i < m; ++i)
            {
                init();
                for(int j = i; j < m; ++j)
                {
                    Union(d[j].s, d[j].e);
                    if(find(a) == find(b))
                    {
                        ans = min(ans, d[j].p - d[i].p);
                        break;
                    }
                }
            }
            if(ans == 0x3f3f3f)
                cout<<-1<<endl;
            else
                cout<<ans<<endl;
        }
    }
    return 0;
}
