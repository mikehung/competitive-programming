#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), f(10);
    for (auto &v: a) {
        char ch;
        cin >> ch;
        v = ch-'0';
    }
    for (int i = 1; i < 10; ++i) {
        cin >> f[i];
    }
    int i = 0;
    while (i < n && a[i] >= f[a[i]]) ++i;
    for (; i < n && a[i] <= f[a[i]]; ++i) {
        a[i] = f[a[i]];
    }
    for (auto &v: a) cout << v; cout << endl;
    return 0;
}
