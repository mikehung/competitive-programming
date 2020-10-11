#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> cnt(1005);
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            cnt[u]++, cnt[v]++;
        }
        if (cnt[x] <= 1) {
            cout << "Ayush" << '\n';
        } else {
            cout << (n % 2 ? "Ashish" : "Ayush") << '\n';
        }
    }
    return 0;
}
