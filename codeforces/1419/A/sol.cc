#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool odd = false, even = false;
        for (int i = 0; i < n; ++i) {
            int v = s[i]-'0';
            if ((i+1) % 2) {
                if (v % 2) odd = true;
            } else {
                if (v % 2 == 0) even = true;
            }
        }
        if (n % 2) {
            cout << (odd ? 1 : 2) << '\n';
        } else {
            cout << (even ? 2 : 1) << '\n';
        }
    }
    return 0;
}
