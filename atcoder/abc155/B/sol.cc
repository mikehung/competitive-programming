#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    bool ok = true;
    while (n--) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            if (x % 3 != 0 && x % 5 != 0) ok = false;
        }
    }
    if (ok) cout << "APPROVED\n";
    else cout << "DENIED\n";
    return 0;
}
