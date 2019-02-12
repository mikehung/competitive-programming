#include <bits/stdc++.h>

using namespace std;
int n, k, a[100];
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        ++cur;
        if (i == n-1 || s[i] != s[i+1]) {
            a[s[i] - 'a'] += cur/k;
            cur = 0;
        }
    }
    int mx = 0;
    for (int i = 0; i < 26; ++i) {
        mx = max(mx, a[i]);
    }
    cout << mx << '\n';
    return 0;
}
