#include <iostream>

using namespace std;

int sky[110][110][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, c;
    cin >> n>> q>> c;
    int x, y, s;
    for(int i = 0; i < n; ++i)
    {
        cin >>x >>y >>s;
        ++sky[y][x][s];
    }
    for(int i = 1; i <= 100; ++i)
        for(int j = 1; j <= 100; ++j)
            for(int si = 0; si < 11; ++si)
                sky[i][j][si] += sky[i-1][j][si] + sky[i][j-1][si] - sky[i-1][j-1][si];
    int t, x1, y1, x2, y2;
    while(q--)
    {
        cin >> t>> x1>> y1>> x2>> y2;
        int ans = 0;
        for(int si = 0; si < 11; ++si)
        {
            if(x1 > x2)
            {
                swap(x1, x2);
                swap(y1, y2);
            }
            int temp = sky[y2][x2][si] - sky[y1-1][x2][si] - sky[y2][x1-1][si] + sky[y1-1][x1-1][si];
            ans += temp*((si+t)%(c+1));
        }
        cout << ans<<endl;
    }

    return 0;
}
