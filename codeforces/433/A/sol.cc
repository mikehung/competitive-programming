#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, w, w100 = 0, w200 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> w;
        if (w == 100)
            w100++;
        else
            w200++;
    }
    if ((w100 % 2 == 0) && (w200 % 2 == 0 || (w200 % 2 && w100 >= 2)))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
