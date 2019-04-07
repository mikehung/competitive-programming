#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string ans = "Christmas";
    int D;
    cin >> D;
    for (int i = 0; i < 25-D; ++i) ans += " Eve";
    cout << ans << endl;
    return 0;
}
