#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(105);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int an = 0, step = 1;
        for (int i = 0; i <= 100; ++i) {
            if (cnt[i] >= 2) continue;
            if (cnt[i] == 1) {
                if (step == 1) {
                    step = 0;
                    an += i;
                }
            } else {
                if (step == 1) {
                    an += 2*i;
                } else {
                    an += i;
                }
                break;
            }
        }
        cout << an << '\n';
    }
    return 0;
}
