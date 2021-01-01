#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;

void solve()
{
    int n;
    cin >> n;
    vector<int> ve;
    double x = n;
    ve.push_back(n);
    while (x != 2) {
        x = ceil(sqrt(x));
        ve.push_back(x);
    }

    set<int> se(ve.begin(), ve.end());
    cout << n-2 + (se.size()-1) << '\n';
    for (int i = 3; i <= n; ++i) if (!se.count(i)) {
        cout << i << ' ' << n << '\n';
    }

    for (int i = 1; i < (int)ve.size(); ++i) {
        cout << ve[i-1] << ' ' << ve[i] << '\n';
        cout << ve[i-1] << ' ' << ve[i] << '\n';
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
