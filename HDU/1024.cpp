#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = (ll)1<<60;
 
ll dp[1000007];
ll a[1000007];
ll pre[1000007];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	ll ans;
    int n, m;
	while(scanf("%d %d", &m, &n) != EOF)
    {	
		for(int i = 0; i < n; i++)scanf(" %lld", &a[i]);
		memset(pre, 0, sizeof(pre));
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < m; i++)
        {
			ans = -INF;
			for(int j = i; j < n; j++)
            {
				dp[j] = max(dp[j - 1], pre[j - 1]) + a[j];
				pre[j - 1] = ans;
				ans = max(ans, dp[j]);
			} 
		}
		printf("%lld\n", ans);
	}
	return 0;
}