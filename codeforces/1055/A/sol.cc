#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
int a[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    if (!a[1]) {
        cout << "NO\n";
        return 0;
    }
    if (a[s]) {
        cout << "YES\n";
        return 0;
    }
    if (!b[s]) {
        cout << "NO\n";
        return 0;
    }
    bool ok = false;
    for (int i = s; i <= n; ++i) {
        if (a[i] && b[i])
            ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';

    return 0;
}
