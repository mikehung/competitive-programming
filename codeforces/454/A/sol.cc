#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 105;
int n;
char board[N_MAX][N_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < N_MAX; ++i)
        memset(board[i], '*', sizeof(board[i]));
    int h = n/2;
    for (int i = 0; i < h+1; ++i) {
        for (int j = h-i; j <= h+i; ++j) {
            board[i][j] = board[n-i-1][j] = 'D';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}
