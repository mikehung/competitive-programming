#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n%4) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
