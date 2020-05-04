#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        long long an = 0;
        vector<int> a;
        int pre, cur;
        cin >> pre;
        n--;
        while (n--) {
            cin >> cur;
            if ((cur > 0) != (pre > 0)) {
                an += pre;
                pre = cur;
            } else {
                pre = max(cur, pre);
            }
        }
        an += pre;
        cout << an << '\n';
    }
    return 0;
}
