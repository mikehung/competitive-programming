#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> a;
    int sum = 0;
    for (int i = 0; i < n; ++i) if (s[i] != t[i]) {
        if (s[i] == '0') a.push_back(1);
        else a.push_back(-1);
        sum += a.back();
    }
    if (sum != 0) {
        cout << -1 << '\n';
        return 0;
    }

    int mx = 0, cur = 0;
    for (int i = 0; i < a.size(); ++i) {
        cur += a[i];
        if (cur < 0) cur = 0;
        mx = max(mx, abs(cur));
    }
    cur = 0;
    for (int i = 0; i < a.size(); ++i) {
        cur += a[i];
        if (cur > 0) cur = 0;
        mx = max(mx, abs(cur));
    }
    cout << mx << '\n';
    return 0;
}
