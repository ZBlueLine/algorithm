#include <iostream>
#include <cstring>

using namespace std;

int a[100010];
int b[100010];
bool vis[100010];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[a[i]];
        int res = n;
        for(int i = 0; i < n; ++i)
        {
            int tmp = i;
            if(b[tmp] != i&&vis[i]==false)
            {
                --res;
                while(vis[tmp]==false)
                {
                    vis[tmp] = true;
                    tmp = b[tmp];
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}