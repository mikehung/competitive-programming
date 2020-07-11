#include <bits/stdc++.h>

using namespace std;

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
        int an = 0, cnt = s[0] == '(' ? 1 : -1;
        if (cnt < 0) {
            an++;
            cnt = 0;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt < 0) {
                an++;
                cnt = 0;
            }
        }
        cout << an << '\n';
    }
    return 0;
}
