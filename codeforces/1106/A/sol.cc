#include <bits/stdc++.h>

using namespace std;

const int MAX = 511;
int n;
string m[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> m[i];
    int ans = 0;
    for (int r = 1; r < n-1; ++r) for (int c = 1; c < n-1; ++c) {
        if (m[r][c] == 'X' && m[r-1][c-1] == 'X' &&
            m[r-1][c+1] == 'X' && m[r+1][c-1] == 'X' && m[r+1][c+1] == 'X')
            ++ans;
    }
    cout << ans << endl;
    return 0;
}
