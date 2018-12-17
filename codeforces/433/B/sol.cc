#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
int n, m, type, l, r;
long long a[MAX], b[MAX], c[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        b[i+1] = a[i] + b[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n; ++i) {
        c[i+1] = a[i] + c[i];
    }
    cin >> m;
    while (m--) {
        cin >> type >> l >> r;
        if (type == 1) {
            cout << b[r] - b[l-1] << '\n';
        } else {
            cout << c[r] - c[l-1] << '\n';
        }
    }
    return 0;
}
