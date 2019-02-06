#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int l, r, n = s.size();
    for (l = 0; l < n; ++l) {
        if (s[l] == '[') break;
    }
    for (l = l+1; l < n; ++l) {
        if (s[l] == ':') break;
    }
    for (r = n-1; r >= 0; --r) {
        if (s[r] == ']') break;
    }
    for (r = r-1; r >= 0; --r) {
        if (s[r] == ':') break;
    }
    if (l >= r) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = 4;
    for (int i = l+1; i < r; ++i) if (s[i] == '|') {
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}
