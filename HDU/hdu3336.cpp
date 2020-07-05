#include <iostream>

using namespace std;

int Next[200010];

void getnext(string a)
{
    int len = a.length();
    int i = -1;
    int j = 0;
    Next[0] = -1;
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
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        int ans = 0;
        int len;
        cin >> len;
        cin >> s;
        getnext(s);
        for(int i = 1; i <= len; ++i)
        {
            if(Next[i])
                ++ans;
        }
        ans = (ans+len)%10007;
        cout <<ans<<endl;
    }
    return 0;
}
