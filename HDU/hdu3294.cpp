#include <vector>
#include <iostream>
#include <string>
using namespace std;

int p[520005];
void Manacher(string s) {
    // Insert '#'
    int ans[5];
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    ans[0] = (resCenter - resLen) / 2;
    ans[1] = resLen - 1;
    if(ans[1]<=1)
    {        
        cout <<"No solution!"<<endl;
        return;
    }
    cout <<ans[0]<<' '<<ans[0]+ans[1]-1<<endl;
    cout << s.substr(ans[0], ans[1])<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    char k;
    while(cin >> k)
    {
        cin >> s;
        int len = s.length();
        for(int i = 0; i < len; ++i)
        {
            s[i] -= (k - 'a');
            if(s[i]<'a')
                s[i] += 'z'-'a' + 1;
        }
        Manacher(s);
    }
}
