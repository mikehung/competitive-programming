#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 123;
int n, m;
string a[MAX];
bool b[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int r = 0; r < n; ++r) {
        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j) {
                if (a[r][i] == a[r][j]) {
                    b[r][i] = b[r][j] = true;
                }
            }
        }
    }
    for (int c = 0; c < m; ++c) {
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (a[i][c] == a[j][c]) {
                    b[i][c] = b[j][c] = true;
                }
            }
        }
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (!b[r][c]) {
                cout << a[r][c];
            }
        }
    }
    cout << '\n';
    return 0;
}
