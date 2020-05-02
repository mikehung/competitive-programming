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
        vector<long long> a;
        long long cur = 0;
        for (int i = 0; i < 31; ++i) {
            if (cur + (1ll<<i) > n) {
                if (cur != n) {
                    a.push_back(n-cur);
                }
                break;
            }
            cur += 1ll<<i;
            a.push_back(1ll<<i);
        }
        sort(a.begin(), a.end());

        cout << a.size()-1 << '\n';
        for (int i = 1; i < a.size(); ++i) {
            cout << a[i]-a[i-1] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
