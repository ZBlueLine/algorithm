#include <vector>
#include <iostream>
#include <string>
using namespace std;

int p[220005];
int Manacher(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    int mx = 0, id = 0, resLen = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
        }
    }
    return resLen-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin >> s)
        cout << Manacher(s) << endl;
}
