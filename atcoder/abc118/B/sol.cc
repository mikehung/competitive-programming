#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m;
    vector<int> cnt(m);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            ++cnt[--a];
        }
    }
    int ans = 0;
    for (auto x: cnt) if (x == n) ++ans;
    cout << ans << endl;

    return 0;
}
