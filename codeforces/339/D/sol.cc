#include <bits/stdc++.h>

using namespace std;

const int NMAX = 17;
int n, m, p, q, b;
vector<int> a[NMAX+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < (1<<n); ++i) {
        int x;
        cin >> x;
        a[0].push_back(x);
    }
    int v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1<<(n-i-1)); ++j) {
            if (i & 1)
                v = a[i][2*j] ^ a[i][2*j+1];
            else
                v = a[i][2*j] | a[i][2*j+1];
            a[i+1].push_back(v);
        }
    }
    while (m--) {
        cin >> p >> b;
        a[0][--p] = b;
        for (int i = 0; i < n; ++i) {
            int q = p ^ 1;
            if (i & 1) {
                v = a[i][p] ^ a[i][q];
            } else {
                v = a[i][p] | a[i][q];
            }
            p /= 2;
            a[i+1][p] = v;
        }
        cout << a[n][0] << '\n';
    }
    return 0;
}
