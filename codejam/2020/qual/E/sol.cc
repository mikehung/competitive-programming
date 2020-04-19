#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<bool>> row, col;

bool backtracking(vector<vector<int>> &an, int x, int y)
{
    if (y == n-2) x++, y = 0;
    if (x == n) return true;

    for (int i = 0; i < n; ++i) {
        if (!row[x][i] && !col[y][i]) {
            an[x][y] = i+1;
            row[x][i] = col[y][i] = true;
            if (backtracking(an, x, y+1)) return true;
            an[x][y] = 0;
            row[x][i] = col[y][i] = false;
        }
    }
    return false;
}

void fill(vector<vector<int>> &an, int x, int y)
{
    vector<bool> used(n+1);
    for (int r = 0; r < n; ++r) if (r != x) {
        used[an[r][y]] = true;
    }
    for (int c = 0; c < n; ++c) if (c != y) {
        used[an[x][c]] = true;
    }

    for (int i = 1; i <= n; ++i) if (!used[i]) {
        an[x][y] = i;
        break;
    }
}

void solve()
{
    cin >> n >> k;
    if (k == n+1 || k == n*n-1 || (n == 3 && k%3)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << "POSSIBLE\n";
    if (n == 2) {
        if (k == 2) {
            cout << "1 2\n2 1\n";
        } else {
            cout << "2 1\n1 2\n";
        }
        return;
    }

    int type;
    array<int, 3> arr;
    if (k % n == 0) {
        type = 0;
        arr[0] = arr[1] = arr[2] = k/n;
    } else {
        for (int i = 1; i <= n; ++i) {
            arr[0] = i;
            int left = k - (arr[0])*(n-2);
            arr[1] = left / 2;
            arr[2] = left - arr[1];
            if (arr[1] > n || arr[2] > n) continue;
            if (arr[0] != arr[1] && arr[0] != arr[2]) break;
        }
        if (arr[1] == arr[2]) type = 1;
        else type = 2;
    }
    vector<int> cycle(n);
    if (type == 0) {
        for (int i = 0; i < n; ++i) {
            cycle[i] = arr[0]+i;
            if (cycle[i] > n) cycle[i] -= n;
        }
    } else if (type == 1) {
        cycle[0] = arr[0], cycle[1] = arr[1];
        int j = 2;
        for (int i = 1; i <= n; ++i) {
            if (i != arr[0] && i != arr[1]) {
                cycle[j++] = i;
            }
        }
    } else {
        cycle[0] = arr[0], cycle[1] = arr[2], cycle[n-1] = arr[1];
        int j = 2;
        for (int i = 1; i <= n; ++i) {
            if (i != arr[0] && i != arr[1] && i != arr[2]) {
                cycle[j++] = i;
            }
        }
    }

    vector<vector<int>> an(n, vector<int>(n));
    int bound;
    if (type == 0) bound = n;
    else if (type == 1) bound = n-3;
    else bound = n-2;
    for (int i = 0; i < bound; ++i) {
        for (int j = 0, sj = i; j < n; ++j, sj = (sj+1)%n) {
            an[i][sj] = cycle[j];
        }
    }

    if (type > 0) {
        // fill left-down corner
        an[n-2][n-2] = arr[1];
        an[n-1][n-1] = arr[2];
        an[n-2][n-1] = an[n-1][n-2] = arr[0];
        // fill n-3 row
        if (type == 1) {
            an[n-3][0] = arr[1];
            an[n-3][n-3] = arr[0];
            fill(an, n-3, n-2);
            fill(an, n-3, n-1);
            for (int c = 1; c < n-3; ++c) {
                fill(an, n-3, c);
            }
        }

        row = vector<vector<bool>>(n, vector<bool>(n));
        col = vector<vector<bool>>(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (an[i][j]) {
                row[i][an[i][j]-1] = true;
                col[j][an[i][j]-1] = true;
            }
        }
        backtracking(an, n-2, 0);
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << an[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
