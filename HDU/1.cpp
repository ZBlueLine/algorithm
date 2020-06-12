#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

int ta[1000];

bool sch(int a, int len)
{
    int l = 0;
    int r = len;
    int mid;
    while(l <= r)
    {
        mid = (l+r>>1);
        if(a >= ta[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    cout << r<<endl;
    if(ta[r] == a)
        return true;
    return false;
}

int main()
{
    for(int i = 1; i < 90; ++i)
        ta[i] = i;
    sch(58, 89);
    return 0;
}