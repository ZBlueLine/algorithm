#include <bits/stdc++.h>

using namespace std;

int indeg[510];
bool vis[510][510];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    while(cin >> N >>M)
    {
        memset(indeg, 0, sizeof(indeg));
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b;
            if(!vis[a][b])
            {
                vis[a][b] = true;
                ++indeg[b];
            }
        }
        int tmp = N;
        while(N)
        {
            int i = 1;
            while(indeg[i])++i;
            indeg[i] = -1;
            cout <<i;
            --N;
            for(int j = 1; j <= tmp; ++j)
            {
                if(j == i)continue;
                if(vis[i][j])--indeg[j];
            }
            if(N)cout<<' ';
            else cout <<endl;
        }
    }
    return 0;
}
