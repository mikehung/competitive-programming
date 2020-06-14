#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mx = -1;
    cin >> n;
    vector<int> a(n), an(n, -1);
    for (auto &it: a) {
        cin >> it;
        mx = max(it, mx);
    }
    vector<bool> used(mx);
    for (int i = n-1; i > 0; --i) {
        if (a[i] != a[i-1]) {
            an[i] = a[i-1];
            used[an[i]] = true;
        }
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (an[i] == -1) {
            while (j < mx && used[j]) ++j;
            if (j < mx) an[i] = j++;
        }
    }
    for (int i = 0; i < n; ++i) if (an[i] == -1) an[i] = mx+2;
    for (auto v: an) cout << v << ' '; cout << endl;

    return 0;
}
