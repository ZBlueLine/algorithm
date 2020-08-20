#include <bits/stdc++.h>

using namespace std;

map<int, int> cnt;
int audio[200010];
int subtitles[200010];
pair<int, int> movie[200010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int temp;
    cin >> n;

    pair<int, int> ans = make_pair(-1, -1);

    for(int i = 0; i < n; ++i)
    {
        cin >> temp;
        ++cnt[temp];
    }
    cin >> m;
    int res = 0;
    for(int i = 1; i <= m; ++i)
    {
        cin >> movie[i].first;
        movie[i].first = cnt[movie[i].first];
    }
    for(int i = 1; i <= m; ++i)
    {
        cin >> movie[i].second;
        movie[i].second = cnt[movie[i].second];
    }
    for(int i = 1; i <= m; ++i)
    {
        if(movie[i]>ans)
        {
            ans = movie[i];
            res = i;
        }
    }
    cout << res<<endl;
    return 0;
}
