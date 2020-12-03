#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;
vector<int> a;

bool sorted(int l, int r)
{
    for (int i = l; i+1 < r; ++i) {
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    a = vector<int>(n);
    for (auto &it: a) cin >> it;
    if (sorted(0, n)) {
        cout << 0 << '\n';
        return;
    }

    int an = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > x) {
            ++an;
            swap(a[i], x);
            if (sorted(0, n)) {
                cout << an << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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
