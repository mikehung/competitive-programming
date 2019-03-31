#include <bits/stdc++.h>

using namespace std;

long long H, n, mn = 1e9;
vector<long long> d;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> n;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        d.push_back(x);
        if (i) d[i] += d[i-1];
        if (mn >= d[i]) mn = d[i];
    }
    for (int i = 0; i < n; ++i) {
        if (H+d[i] <= 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    if (d[n-1] >= 0) {
        cout << -1 << endl;
        return 0;
    }
    long long rn = (H+mn) / (-d[n-1]);
    if ((H+mn) % (-d[n-1])) rn++;
    long long an = rn * n;
    H += rn * d[n-1];
    for (int i = 0; i < n; ++i) {
        if (H+d[i] <= 0) {
            cout << an + i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
