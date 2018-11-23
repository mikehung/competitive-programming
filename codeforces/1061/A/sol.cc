#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    cout << (s/n) + int(s%n != 0) << '\n';
    return 0;
}
