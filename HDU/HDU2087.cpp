#include <iostream>

using namespace std;

int Next[1010];

void getnext(string a)
{
    int len = a.length();
    int i = -1;
    int j = 0;
    while(j < len-1)
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

int main ()
{
    Next[0] = -1;
    string s, s2;
    while(cin >>s)
    {
        if(s == "#")
            break;
        cin >> s2;
        cout <<kmp(s, s2)<<endl;
    }
    return 0;
}
