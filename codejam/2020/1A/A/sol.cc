#include <bits/stdc++.h>

using namespace std;

bool check(vector<string> &v, bool backward)
{
    if (v.empty()) return true;

    if (backward) {
        for (auto &s: v) {
            reverse(s.begin(), s.end());
        }
    }

    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        for (int j = 0; j < v[i-1].size(); ++j) {
            if (v[i-1][j] != v[i][j]) return false;
        }
    }

    if (backward) {
        for (auto &s: v) {
            reverse(s.begin(), s.end());
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> pre, suf;
    string middle;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int first = s.find('*'), last = s.find_last_of('*');
        pre.push_back(s.substr(0, first));
        suf.push_back(s.substr(last+1));
        if (first != last) {
            string t;
            for (int j = first+1; j < last; ++j) {
                if (s[j] != '*') middle += s[j];
            }
        }
    }

    if (!check(pre, 0) || !check(suf, 1)) {
        cout << "*\n";
    } else {
        string an = pre.back() + middle + suf.back();
        cout << an << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
