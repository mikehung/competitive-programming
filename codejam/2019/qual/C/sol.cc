#include <bits/stdc++.h>

using namespace std;

pair<int, int> factor(int x)
{
    for (long long i = 2; i*i <= x; ++i) {
        if (x % i == 0) return make_pair(i, x/i);
    }
    assert(false);
}

void solve(int testcase)
{
    int N, L, start = 1;
    cin >> N >> L;
    vector<int> a(L), ans(L+1);
    for (int i = 0; i < L; ++i) {
        cin >> a[i];
        if (i && a[i] != a[i-1]) start = i;
    }
    auto par = factor(a[start]);
    if (a[start-1] % par.first == 0) {
        ans[start] = par.first;
        ans[start+1] = par.second;
    } else {
        ans[start] = par.second;
        ans[start+1] = par.first;
    }
    for (int i = start-1; i >= 0; --i) {
        ans[i] = a[i] / ans[i+1];
    }
    for (int i = start+2; i < L+1; ++i) {
        ans[i] = a[i-1] / ans[i-1];
    }
    for (int i = 1; i < L; ++i) {
        ans[i+1] = a[i] / ans[i];
    }
    map<int, int> mp;
    for (auto v: ans) mp[v];
    int offset = 0;
    for (auto &kv: mp) kv.second = offset++;
    cout << "Case #" << testcase << ": ";
    for (auto v: ans) {
        cout << (char) ('A' + mp[v]);
    }
    cout << '\n';
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
