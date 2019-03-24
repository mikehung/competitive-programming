#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = n, need = 0;
        for (int i = 0; i < n-1 && s[i] == '<'; ++i) {
            ++need;
        }
        ans = min(ans, need);
        need = 0;
        for (int i = n-1; i >= 1 && s[i] == '>'; --i) {
            ++need;
        }
        ans = min(ans, need);
        cout << ans << '\n';
    }
    return 0;
}
