#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;

int stone[500010];

bool check(int len, int n, int m)
{
    int pos = 0;
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(stone[i]-pos>len)
            return false;
        if(stone[i+1] - stone[i]>len)
            return false;
        if(stone[i+1]-pos>len)
        {
            ++cnt;
            pos = stone[i];
        }
    }
    return cnt<m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 1;
    int L, n, m;
    while(cin >> L >> n >> m)
    {
        memset(stone, 0, sizeof(stone));
        cnt = 1;
        stone[0] = 0;
        stone[1] = L;
        for(int i = 0; i < n; ++i)
            cin >> stone[++cnt];
        sort(stone, stone+cnt+1);
        int l = 0, r = L;
        while(l <= r)
        {
            int mid = l+(r-l>>1);
            int pos = 0;
            /*
            for(int i = 0; i < m; ++i)
            {
                pos += mid;
                pos = stone[upper_bound(stone, stone+cnt+1, pos)-stone-1];
            }*/
            if(!check(mid, n, m))
                l = mid+1;
            else
                r = mid-1;
        }
        cout << l<<endl;
    }
    return 0;
}