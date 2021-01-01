#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;

void solve()
{
    int n, k, m = 20;
    string s;
    cin >> n >> k >> s;

    m = min(m, k);
    deque<int> d, d1;
    int sz = (1<<m)+7;
    vector<bool> valid(sz, true);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i >= k-m) d.push_back(i);
            d1.push_back(i);
        }
        if (d.size() && i-d.front() >= m) d.pop_front();
        if (d1.size() && i-d1.front() >= k) d1.pop_front();

        if (d1.size() == d.size() && i >= k-1) {
            int x = 0;
            for (int j: d) {
                x |= 1<<(i-j);
            }
            valid[x] = false;
        }
    }

    int mex = 0;
    while (!valid[mex]) mex++;

    if (mex == 1<<m) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string an(k, '0');
        for (int i = 0; i < m; ++i) if (mex>>i&1) {
            an[k-i-1] = '1';
        }
        cout << an << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcases = 1;
    if (MULTI_TESTCASES) cin >> testcases;
    while (testcases--) solve();
    return 0;
}
