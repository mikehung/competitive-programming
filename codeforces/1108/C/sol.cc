#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+123;
int n, mn = MAX;
string s, ans;
vector<vector<char>> colors = {
    {'R', 'G', 'B'},
    {'R', 'B', 'G'},
    {'B', 'R', 'G'},
    {'B', 'G', 'R'},
    {'G', 'B', 'R'},
    {'G', 'R', 'B'}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < colors.size(); ++i) {
        int diff = 0;
        string t;
        for (int p = 0; p < n; ++p) {
            t += colors[i][p%3];
            if (colors[i][p%3] != s[p]) ++diff;
        }
        if (diff < mn) {
            mn = diff;
            ans = t;
        }
    }
    cout << mn << '\n' << ans << '\n';

    return 0;
}
