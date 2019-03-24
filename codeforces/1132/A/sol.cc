#include <bits/stdc++.h>

using namespace std;

void bye()
{
    cout << 0 << '\n';
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a != d) bye();
    if (c > 0 && a == 0) bye();

    cout << 1 << '\n';
    return 0;
}
