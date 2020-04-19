#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        for (int i = 0; i < b; ++i) {
            s += 'a'+i;
        }
        for (int i = b; i < a; ++i) {
            s += s[i%b];
        }
        while (n > a) {
            cout << s;
            n -= a;
        }
        if (n) {
            cout << s.substr(0, n);
        }
        cout << '\n';
    }
    return 0;
}
