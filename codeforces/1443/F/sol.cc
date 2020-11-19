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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k), used(n);
        map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            cin >> b[i];
            used[pos[b[i]]] = 1;
        }
        const int M = 998244353;
        ll an = 1;
        for (int i = 0; i < k; ++i) {
            int cnt = 0, p = pos[b[i]];
            if (p-1 >= 0 && used[p-1] == 0) ++cnt;
            if (p+1 < n && used[p+1] == 0) ++cnt;
            an *= cnt;
            an %= M;
            used[p] = 0;
        }
        cout << an << '\n';
    }
    return 0;
}
