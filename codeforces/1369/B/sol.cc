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
        int i1 = n, i2 = -1;
        string head, end, an;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') head += '0';
            else {
                i1 = i;
                break;
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == '1') end += '1';
            else {
                i2 = i;
                break;
            }
        }
        if (i1 < i2) {
            an = head + '0' + end;
        } else {
            an = head + end;
        }
        cout << an << '\n';
    }
    return 0;
}
