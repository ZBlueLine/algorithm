#include <iostream>

using namespace std;

int Next[1010];

void getnext(string a)
{
    int len = a.length();
    int i = -1;
    int j = 0;
    while(j < len - 1)
    {
        if(i == -1||a[i] == a[j])
        {
            ++i;
            ++j;
            Next[j] = i;
        }
        else if(Next[i]!=Next[j])
        {
            i = Next[i];
        }
    }
    for(int i = 0; i < len; ++i)
    {
        cout << Next[i]<<endl;
    }
}

int main ()
{
    Next[0] = -1;
    string s, s2;
    while(cin >>s>>s2)
    {
        getnext(s);
    }
    return 0;
}
