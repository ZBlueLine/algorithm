#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int Next[110];

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

int kmp(string a, string b)
{
    int ans = 0;
    getnext(b);
    int lena = a.length();
    int lenb = b.length();
    for(int ia = 0, ib = 0; ia < lena;)
    {
        while(ib == -1||(a[ia] == b[ib]&&ia < lena&&ib<lenb))
        {
            ++ia;
            ++ib;
        }
        if(ib == lenb)
        {
            ++ans;
            ib = 0;
        }
        else 
            ib = Next[ib];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    string s[110];
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> s[i];
        int len = s[0].length();
        string temp;
        int flag = true;
        for(int i = len; i >= 1; --i)
        {
            for(int k = 0; k+i<=len; ++k)
            {
                flag = true;
                temp = s[0].substr(k, i);
                for(int j = 1; j < n; ++j)
                {
                    if(!kmp(s[j], temp))
                    {
                        reverse(temp.begin(), temp.end());
                        if(!kmp(s[j], temp))
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
            {
                cout << i <<endl;
                break;
            }
        }
        if(!flag)
            cout <<0<<endl;
    }
    return 0;
}