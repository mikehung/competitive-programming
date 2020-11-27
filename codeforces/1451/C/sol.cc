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
        int n, k;
        cin >> n >> k;
        string ss, tt;
        cin >> ss >> tt;
        priority_queue<int, vector<int>, greater<int>> s, t;
        for (int i = 0; i < n; ++i) {
            s.push(ss[i]-'a');
            t.push(tt[i]-'a');
        }
        bool ok = true;
        while (s.size() && ok) {
            int x = s.top(), y = t.top();
            s.pop(), t.pop();
            if (x == y) {
                continue;
            }
            if (x > y || s.size() < k-1) {
                ok = false;
                break;
            }
            for (int i = 1; i < k; ++i) {
                if (s.top() != x) {
                    ok = false;
                    break;
                }
                s.pop();
            }
            if (ok) {
                for (int i = 1; i < k; ++i) {
                    s.push(y);
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
