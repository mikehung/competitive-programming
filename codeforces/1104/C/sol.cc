#include <bits/stdc++.h>

using namespace std;

string s;
vector<pair<int, int>> ans, zero = {{1, 1}, {3, 1}}, one;
int c0, c1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 4; ++i) one.push_back({i, 3});
    cin >> s;
    for (char ch: s) {
        if (ch == '0') {
            int x = c0++ % 2;
            cout << zero[x].first << ' ' << zero[x].second << '\n';
        } else {
            int x = c1++ % 4;
            cout << one[x].first << ' ' << one[x].second << '\n';
        }
    }
    return 0;
}
