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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int an = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) an++;
        }
        cout << (an+1) / 2 << '\n';
    }
    return 0;
}
