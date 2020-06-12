// Problem : Aggressive cows
// URL : http://poj.org/problem?id=2456

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int x[100010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x, x+n);
    int l = 0;
    int r = 1000000000;
    while(l <= r)
    {
        int cnt = 0;
        int mid = l+(r-l>>1);
        int npos = -1;
        for(int i = 0; i < n; ++i)
        {
            if(npos == -1)
            {
                npos = x[i];
                ++cnt;
                continue;
            }
            if(x[i]-npos>=mid)
            {
                ++cnt;
                npos = x[i];
            }
            if(cnt == c)
                break;
        }
        if(cnt==c)
            l = mid+1;
        else
            r = mid-1;
    }
    cout << r<<endl;
    return 0;
}
