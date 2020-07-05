#include <iostream>
#include <cstring>
using namespace std;

int matrix[1010][1010];
int sum[1010][1010];


int main()
{
    int t;
    cin >> t;
    int n, m, x, y;
    while(t--)
    {
        cin >> n >> m >> x >> y;
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                cin >> matrix[i][j];
                sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+matrix[i][j];
            }
        }
        int ans = -1;
        for(int i = 1; i <= n-x+1; ++i)
        {
            for(int j = 1; j <= m-y+1; ++j)
            {
                int cnt = sum[i+x-1][j+y-1]-sum[i+x-1][j-1]-sum[i-1][j+y-1]+sum[i-1][j-1];
                ans = max(ans, cnt);
            }
        }
        cout << ans <<endl;
    }
    return 0;
}