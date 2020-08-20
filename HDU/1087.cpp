#include <bits/stdc++.h>

using namespace std;

int num[1010];
int dp[1010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int ans;
    while(cin >> n&&n)
    {
        for(int i = 0; i < n; ++i)
        {
            cin >> num[i];
            dp[i] = num[i];
        }
        ans = num[0];
        for(int i = 1; i < n; ++i)
        {
            for(int j = i-1; j >= 0; --j)
            {
                if(num[i] > num[j])
                    dp[i] = max(dp[i], num[i] + dp[j]);
                ans = max(ans, dp[i]);
            }
        }
        cout <<ans<<endl;
    }

    return 0;
}
