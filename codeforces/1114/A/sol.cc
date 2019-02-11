#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z, g, p, b, v;
    bool ans = true;;
    cin >> x >> y >> z >> g >> p >> b;
    if (x > g) {
        ans = false;
        goto END;
    }
    g -= x;
    v = min(z, b);
    z -= v;
    b -= v;
    if (y + z > g + p) {
        ans = false;
        goto END;
    }
END:
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
