#include <bits/stdc++.h>
using namespace std;

int a[1000010], b[1000010];
int maxsum[1000010];
int sum[1000010];

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n)
    {
        int amark = 0, bmark = 0;
        memset(maxsum, 0, sizeof(maxsum));
        maxsum[0] = -1010;
        memset(sum, 0, sizeof(sum));
        char op;
        int num;
        for(int i = 0; i < n; ++i)
        {
            cin >> op;
            if(op == 'I'||op == 'Q')
            {
                cin >> num;
                if(op == 'I')
                {
                    a[++amark] = num;
                    sum[amark] = sum[amark-1] + num;
                    maxsum[amark] = max(sum[amark], maxsum[amark-1]);
                }
                if(op == 'Q')
                    cout << maxsum[num]<<endl;
            }
            else
            {
                if(op == 'L'&&amark)
                {
                    b[++bmark] = a[amark];
                    --amark;
                }
                if(op == 'D'&&amark)
                    --amark;
                if(op == 'R'&&bmark)
                {
                    a[++amark] = b[bmark];
                    sum[amark] = sum[amark-1] + b[bmark];
                    maxsum[amark] = max(sum[amark], maxsum[amark-1]);
                    --bmark;
                }
            }
            
        }
    }
    return 0;
}
