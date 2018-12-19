#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
int n;
string ans;
vector<pair<string, int>> m[MAX];

bool suffix(const string &s, const string &t)
{
    int d = s.size() - t.size();
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] != s[i+d]) return false;
    }
    return true;
}

bool prefix(const string &s, const string &t)
{
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] != s[i]) return false;
    }
    return true;
}

bool check(const string &s) 
{
    for (int i = 1; i <= n-1; ++i) {
        if (prefix(s, m[i][0].first) && suffix(s, m[i][1].first)) {
            ans[m[i][0].second] = 'P';
            ans[m[i][1].second] = 'S';
            continue;
        }
        if (suffix(s, m[i][0].first) && prefix(s, m[i][1].first)) {
            ans[m[i][0].second] = 'S';
            ans[m[i][1].second] = 'P';
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 2*n-2; ++i) {
        string s;
        cin >> s;
        m[s.size()].push_back(make_pair(s, i));
    }

    ans.resize(2*n-2);
    if (check(m[n-1][0].first + m[n-1][1].first.back())) {
        cout << ans << '\n';
        return 0;
    }

    if (check(m[n-1][1].first + m[n-1][0].first.back())) {
        cout << ans << '\n';
        return 0;
    }

    return 0;
}
