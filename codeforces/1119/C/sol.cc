#include <bits/stdc++.h>

using namespace std;

const int MAX = 511;
int a[MAX][MAX], b[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) cin >> a[r][c];
    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) cin >> b[r][c];
    for (int r = 1; r < n; ++r) for (int c = 1; c < m; ++c) if (a[r][c] != b[r][c]) {
        a[r][c] ^= 1;
        a[0][c] ^= 1;
        a[r][0] ^= 1;
        a[0][0] ^= 1;
    }
    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) if (a[r][c] != b[r][c]) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}
