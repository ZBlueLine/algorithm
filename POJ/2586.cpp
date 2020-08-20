
#include <bits/stdc++.h>
using namespace std;

char ch[1005], ans[1005];
int f[1005][1005];
int minn(int i, int j)
{return ch[i] <= ch[j] ? i : j;}
void st(int n)
{
    int i, j;
    int k = (int)(log(double(n))/log(2.0));
    for(i = 0; i < n; i++)
        f[i][0] = i;
    for(j = 1; j <= k; j++)
        for(i = 0; i + (1 << j) - 1 < n; ++i)
        {
            int m = i + (1 << (j - 1));
            f[i][j] = minn(f[i][j - 1], f[m][j - 1]);
        }
}
int rmq(int i, int j)		
{
    int k = (int)(log(double(j - i + 1))/log(2.0));
    int t, m;
    m = j - (1 << k) + 1;
    return minn(f[i][k], f[m][k]);
}
int main()
{
    int m, k, n, kk;
    int maxn = 1000000;
    while(cin>>ch>>m)
    {
        int len = strlen(ch);
        if(len <= m)
        {
            cout<<0<<endl;
            continue;
        }
        st(len);
        n = len - m;
        k = 0;
        for(int j = 1; j <= n; j++)	
        {
            kk = rmq(k, m + j - 1);
            k = kk + 1;
            ans[j] = ch[kk];
        }
        int flag = 0;
        for(int j = 1; j <= n; j++)
        {
            if(ans[j] != '0')
            {
                cout<<ans[j];
                flag = 1;
            }
            else if(flag || j == n)
                cout<<ans[j];
        }
        cout<<endl;
    }
    return 0;
}
