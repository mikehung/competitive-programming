#include <bits/stdc++.h>

using namespace std;


void solve(string S)
{
    int y = stoi(S.substr(0, 4));
    int m = stoi(S.substr(5, 2));
    int d = stoi(S.substr(8, 2));
    if (y < 2019 || (y == 2019 && m < 4) || (y == 2019 && m == 4 && d <= 30)) cout << "Heisei\n";
    else cout << "TBD\n";
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
