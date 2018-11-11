#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < n; ++i) {
        b[i] = s[i+n] - '0';
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool less = true, greter = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= b[i])
            less = false;
        if (a[i] <= b[i])
            greter = false;
    }
    cout << (less || greter ? "YES" : "NO") << '\n';


    return 0;
}
