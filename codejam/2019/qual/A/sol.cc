#include <bits/stdc++.h>

using namespace std;

void solve(int testcase)
{
    string N;
    cin >> N;
    vector<int> a, b, c;
    for (char ch: N) {
        a.push_back(ch-'0');
    }
    reverse(a.begin(), a.end());
    int sz = a.size();
    for (int i = 0; i < sz; ++i) {
        if (a[i] == 4) {
            b.push_back(1);
            c.push_back(3);
        } else {
            b.push_back(a[i]);
            c.push_back(0);
        }
    }
    while (b.size() && b.back() == 0) b.pop_back();
    while (c.size() && c.back() == 0) c.pop_back();
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    cout << "Case #" << testcase << ": ";
    for (auto v: b) cout << v; cout << ' ';
    for (auto v: c) cout << v; cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}
