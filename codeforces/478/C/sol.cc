#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long r, g, b;
    cin >> r >> g >> b;
    if (r > g) swap(r, g);
    if (g > b) swap(g, b);
    if (r > g) swap(r, g);
    if (b >= 2 * (r + g)) cout << r + g << '\n';
    else cout << (r + g + b) / 3 << '\n';
    return 0;
}
