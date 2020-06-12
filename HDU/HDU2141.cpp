#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int a[510], b[510], c[510];
int ta[250010];

inline bool sch(int a, int len)
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
    if(r>=0&&r<=len&&ta[r] == a)
        return true;
    return false;
}


int main()
{
    int L, M, N;
    int cas = 0;
    int Q;
    while(scanf("%d %d %d", &L, &M, &N) != EOF) {
        for(int i = 0; i < L; ++i)
            scanf("%d", &a[i]);
        for(int i = 0; i < M; ++i)
            scanf("%d", &b[i]);
        for(int i = 0; i < N; ++i)
            scanf("%d", &c[i]);
        int cnt = -1;
        for(int i = 0; i < L; ++i)
            for(int j = 0; j < M; ++j)
                ta[++cnt] = a[i]+b[j];
        sort(ta, ta+cnt+1);
        scanf("%d", &Q);
        printf("Case %d:\n", ++cas);  
        while(Q--)
        {
            int q;
            scanf("%d", &q);
            int i;
            for(i = 0; i < N; ++i)
            {
                int tq = q-c[i];
                if(sch(tq, cnt))  
                {
                    printf("YES\n");
                    break;
                }
            }
            if(i>=N)
                printf("NO\n");
        }
    }
    return 0;
}