#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;

ll clo[100020];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    while(cin >> N)
    {
        for(int i = 0; i < N; ++i)
            cin >> clo[i];
        cin >> K;
        ll l, r;
        l = 0;
        r = 1e14;
        ll mid = 0;
        ll needtimes;
        while(l <= r)
        {
            bool flag = true;
            needtimes = 0;
            mid = l + (r-l>>1);
            for(int i = 0; i < N; ++i)
            {
                if(K == 1)
                {
                    if(clo[i]>mid)
                        flag = false;
                }
                else if(clo[i]>mid)
                {
                    int ta, tb;
                    ta = clo[i]-mid;
                    tb = K-1;
                    needtimes += ta/tb;
                    if(ta%tb!=0)
                        ++needtimes;
                }
            }
            if(needtimes>mid||!flag)
                l = mid+1;
            else
                r = mid-1;
        }
        cout <<l<<endl;
    }

    return 0;
}