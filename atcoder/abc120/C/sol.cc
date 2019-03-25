#include <bits/stdc++.h>

using namespace std;


void solve(string S)
{
    int c0 = 0;
    for (auto &c: S) {
        if (c == '0') ++c0;
    }
    cout << 2 * min(c0, (int)S.size()-c0) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    solve(S);
    return 0;
}
