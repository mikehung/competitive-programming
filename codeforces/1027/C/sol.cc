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
        map<int, int> sticks;
        cin >> n;
        int ok = -1;
        while (n--) {
            int a;
            cin >> a;
            if (++sticks[a] == 4) {
                ok = a;
            }
        }
        if (ok != -1) {
            for (int i = 0; i < 4; ++i)
                cout << ok << ' ';
            cout << '\n';
            continue;
        }
        vector<long long> s;
        for (auto &kv: sticks) {
            if (kv.second > 1) {
                s.push_back(kv.first);
            }
        }
        long long a1 = s[0], a2 = s[1], b1, b2;
        for (int i = 1; i < s.size()-1; ++i) {
            b1 = s[i], b2 = s[i+1];
            if ((b1*b2)*((a1*a1)+(a2*a2)) > (a1*a2)*((b1*b1)+(b2*b2)))
                a1 = b1, a2 = b2;
        }
        cout << a1 << ' ' << a1 << ' ' << a2 << ' ' << a2  << '\n';
    }
    return 0;
}
