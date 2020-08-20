#include <bits/stdc++.h>

using namespace std;

// inline int lg(int a)
// {
//     return ceil(log10(a)/log10(2));
// }

int song[400007];
int disong[400007];
int sum[400007];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, I;
    int A,K;
    int Max = -1;
    K = 1;
    cin >> n>> I;
    I *= 8;
    A = I/n;
    if(A>=19)
    {
        cout << 0 <<endl;
        return 0;
    }
    K = 1<<A;
    for(int i = 1; i <= n; ++i)
    {
        cin >> song[i];
        disong[i] = song[i];
    }
    sort(disong+1, disong+n+1);
    int len = unique(disong+1, disong+n+1)-disong-1;
    int temp;
    for(int i = 1; i <= n; ++i)
    {
        temp = lower_bound(disong+1, disong+len+1, song[i])-disong;
        ++sum[temp];
    }
    for(int i = 1; i <= len; ++i)
        sum[i] += sum[i-1];
    for(int i = 1; i+K-1 <= len; ++i)
    {
        // cout <<sum[i+K-1]-sum[i-1]<<"---"<<i-1<<"---"<<i+K-1<<endl;
        Max = max(sum[i+K-1]-sum[i-1], Max);
    }
    if(Max == -1)
        cout <<0<<endl;
    else
        cout <<n-Max<<endl;
    return 0;
}
