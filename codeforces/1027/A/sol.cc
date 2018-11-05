#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> s;
        bool ok = true;
        for (int j = 0; j < n/2; ++j) {
            int a = s[j]-'0', b = s[n-j-1]-'0';
            if (a < b) swap(a, b);
            if (a != b && a != b+2)
                ok = false;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
