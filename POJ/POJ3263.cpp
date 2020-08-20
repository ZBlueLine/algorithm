#include <iostream>
#include <map>
using namespace std;

int cow[1000007];
map<int, map<int, bool> > Map;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, I, H, R;
    cin >> N>> I>> H>> R;
    cow[1] = H;
    int a, b;
    for(int i = 0; i < R; ++i)
    {
        cin >> a>> b;
        if(Map[a][b])continue;
        if(a>b)swap(a, b);
        Map[a][b] = true;
        Map[b][a] = true;
        --cow[a+1];
        ++cow[b];
    }
    for(int i = 2; i <= N; ++i)
        cow[i] += cow[i-1];
    for(int i = 1; i <= N; ++i)
        cout <<cow[i]<<endl;
    return 0;
}