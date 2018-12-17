#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    vector<string> cake;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        string s;
        cin >> s;
        cake.push_back(s);
    }
    vector<vector<bool>> eat(r, vector<bool>(c));
    for (int i = 0; i < r; ++i) {
        bool ok = true;
        for (int j = 0; j < c; ++j) {
            if (cake[i][j] == 'S') ok = false;
        }
        if (ok) {
            for (int j = 0; j < c; ++j) {
                eat[i][j] = true;
            }
        }
    }
    for (int j = 0; j < c; ++j) {
        bool ok = true;
        for (int i = 0; i < r; ++i) {
            if (cake[i][j] == 'S') ok = false;
        }
        if (ok) {
            for (int i = 0; i < r; ++i) {
                eat[i][j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) if (eat[i][j]) ++cnt;
    cout << cnt << '\n';
    return 0;
}
