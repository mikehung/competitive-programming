#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;

void solve()
{
    string s;
    cin >> s;
    cout << s.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcases = 1;
    if (MULTI_TESTCASES) cin >> testcases;
    while (testcases--) solve();
    return 0;
}
