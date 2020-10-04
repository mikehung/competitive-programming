#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    const int M = (int) 1e9+7;
    ll an = 0, a = 0, ab = 0, cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            a = (a+cnt) % M;
        } else if (s[i] == 'b') {
            ab = (ab+a) % M;
        } else if (s[i] == 'c') {
            an = (an+ab) % M;
        } else {
            an = (3 * an % M + ab) % M;
            ab = (3 * ab % M + a) % M;
            a = (3 * a % M + cnt) % M;
            cnt = cnt * 3 % M;
        }
    }
    cout << an << '\n';
    return 0;
}
