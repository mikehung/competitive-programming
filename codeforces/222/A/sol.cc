#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    bool ok = true;
    cin >> n >> k;
    vector<int> a(n+1);
    --k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = k+1; i < n; ++i)
        if (a[i] != a[k])
            ok = false;
    if (!ok)
        cout << -1 << '\n';
    else {
        while (k-1 >= 0 && a[k-1] == a[k]) --k;
        cout << k << '\n';
    }
    return 0;
}
