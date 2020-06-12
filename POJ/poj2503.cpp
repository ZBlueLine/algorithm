// Problem : Babelfish
// URL : http://poj.org/problem?id=2503

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

map<string, string> Map;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    bool flag1 = true;
    while(getline(cin, s))
    {   
        if(s=="")
        {
            flag1 = false;
            continue;
        }
        if(flag1)
        {
            string a = "", b = "";
            int len = s.length();
            int i;
            bool flag = false;
            for(i = 0; i < len; ++i)
            {
                if(s[i] == ' ')
                {
                    flag = true;
                    continue;
                }
                if(flag)
                    b += s[i];
                else
                    a += s[i];
            }
            Map[b] = a;
        }
        else
        {
            if (Map.find(s) == Map.end())
                cout <<"eh"<<endl;
            else
                cout <<Map[s]<<endl;
        }
        
    }
    return 0;
}
