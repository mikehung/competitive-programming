#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string b;
        cin >> b;
        cout << b[0];
        for (int i = 1; i < b.size(); i += 2) {
            cout << b[i];
        }
        cout << '\n';
    }
    return 0;
}
