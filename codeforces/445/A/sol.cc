#include <bits/stdc++.h>
using namespace std;

const int MAX = 123;
int n, m;
string board[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int r = 0; r < n; ++r) {
        cin >> board[r];
        for (int c = 0; c < m; ++c) {
            if (board[r][c] == '.') {
                board[r][c] = (r+c) & 1 ? 'W' : 'B';
            }
        }
        cout << board[r] << '\n';
    }

    return 0;
}
