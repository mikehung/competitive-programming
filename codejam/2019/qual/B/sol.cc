#include <bits/stdc++.h>

using namespace std;

void solve(int testcase)
{
    int sz;
    string path, ans;
    cin >> sz >> path;
    for (char &c: path) {
        if (c == 'S') ans.push_back('E');
        else ans.push_back('S');
    }
    cout << "Case #" << testcase << ": " << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}
