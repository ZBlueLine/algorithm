#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int Next[1000007];

void getnext(string &a)
{
    int len = a.length();
    int i = -1;
    int j = 0;
    Next[0]=-1;
    while(j < len)
    {
        if(i == -1||a[i] == a[j])
            Next[++j] = ++i;
        else
            i = Next[i];
    }
}
int main ()
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    while(n--)
    {
        int res = 0;
        cin >> s;
        int len = s.length();
        getnext(s);
        for(int i = 0; i <= len-1; ++i)
            res = max(res, Next[i]);
        res = min(res, Next[len]);
        cout << res<<endl;
    }
    return 0;
}
