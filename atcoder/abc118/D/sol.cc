#include <bits/stdc++.h>

using namespace std;

bool bigger(const string &s1, const string &s2)
{
    if (s1.size() != s2.size()) return s1.size() > s2.size();
    for (int i = 0; i < (int) s1.size(); ++i) if (s1[i] != s2[i]) {
        return s1[i] > s2[i];
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        a.insert(x);
    }
    vector<int> match = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    map<int, char> t;
    for (auto x: a) {
        t[match[x]] = x + '0';
    }
    string dp[n+100];
    for (int i = 0; i < n; ++i) if (i == 0 || dp[i] != "") {
        for (auto &kv: t) {
            string s = dp[i] + kv.second;
            if (bigger(s, dp[i+kv.first])) {
                dp[i+kv.first] = s;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
