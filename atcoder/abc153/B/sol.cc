#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, n;
    cin >> h >> n;
    while (n--) {
        int x;
        cin >> x;
        h -= x;
    }
    cout << (h <= 0 ? "Yes" : "No") << endl;
    return 0;
}
