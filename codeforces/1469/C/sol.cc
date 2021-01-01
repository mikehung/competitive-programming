#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &it: a) cin >> it;

    vector<int> lo(n), hi(n); // lower & upper bound of the ground
    lo[0] = hi[0] = a[0];
    for (int i = 1; i < n-1; ++i) {
        if (hi[i-1]+k < a[i]+1 || lo[i-1]+1 > a[i]+k-1+k) {
            cout << "NO\n";
            return;
        }

        lo[i] = max(a[i], lo[i-1]-k+1);
        hi[i] = min(a[i]+k-1, hi[i-1]+k-1);
    }
    int last_st = a[n-1]+1, last_en = a[n-1]+k;
    cout << ((max(last_st, lo[n-2]+1) <= min(last_en, hi[n-2]+k)) ? "YES" : "NO") << '\n';
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
