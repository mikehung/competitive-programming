#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    int an = -1;
    for (int i = 0, j = n-1; ; j--) if (a[i] != a[j]) {
        an = max(an, j - i);
        break;
    }
    for (int i = 0, j = n-1; ; i++) if (a[i] != a[j]) {
        an = max(an, j - i);
        break;
    }
    cout << an << endl;
    return 0;
}
