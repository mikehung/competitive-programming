#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s;
    bool rm = false;
    for (int i = 0; i < n; ++i) {
        if (!rm && (i == n-1 || s[i] - '0' > s[i+1] - '0')) {
            rm = true;
            continue;
        }
        t += s[i];
    }
    cout << t << '\n';
    return 0;
}
