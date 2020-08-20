#include<bits/stdc++.h>

using namespace std;

bool vis[20010];
int w[510], v[510];
int dp[20007];

int main()
{
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int p, q;
    int n;
    cin >> t;
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        cin >> p >> q;
        int tmp = q - p;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> v[i]>>w[i];
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= tmp; ++j)
            {
                if(j - w[i] < 0)
                    continue;
                if(vis[j-w[i]]||j - w[i] == 0)
                {
                    if(dp[j]>0)
                        dp[j] = min(dp[j-w[i]] + v[i], dp[j]);
                    else
                        dp[j] = dp[j - w[i]] + v[i];
                    vis[j] = true;
                }
            }
        }
        if(dp[tmp] == 0)
            cout << "This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[tmp]<<endl;
    }   
    return 0;
}