#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    bool poor = false;
    if (((a == b) && a != c) ||
        ((a == c) && a != b) ||
        ((b == c) && a != b))
        poor = true;

    if (poor) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
