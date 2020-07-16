#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    vector<int> a(n+2), b(m);
    a[0] = a[n+1] = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<int> idx = {0};
    for (int i = 1, j = 0; i <= n && j < m;) {
        if (a[i] == b[j]) {
            idx.push_back(i);
            ++i, ++j;
        } else {
            ++i;
        }
    }
    idx.push_back(n+1);
    if (idx.size() != m+2) {
        cout << -1 << '\n';
        return 0;
    }

    long long an = 0;
    for (int i = 1; i < m+2; ++i) {
        int big = 0, prev = idx[i-1], curr = idx[i], cnt = curr - prev - 1;
        for (int j = prev+1; j < curr; ++j) {
            if (a[prev] < a[j] && a[curr] < a[j]) big++;
        }
        if (big > 0 && cnt < k) {
            cout << -1 << '\n';
            return 0;
        }
        an += (cnt%k) * y;
        cnt -= (cnt%k);
        if (x <= y * k) {
            an += 1ll*cnt/k*x;
        } else if (big > 0) {
            an += 1ll*x + 1ll*(cnt-k)*y;
        } else {
            an += 1ll*cnt*y;
        }
    }
    cout << an << '\n';
    return 0;
}
