#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if (u == s) cout << a-1 << ' ' << b << endl;
    else cout << a << ' ' << b-1 << endl;
    return 0;
}
