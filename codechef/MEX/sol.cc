#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;

bool check(int x)
{
    int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    return x-idx <= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        set<int> se;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            se.insert(x);
        }
        a = vector<int>(se.begin(), se.end());
        n = a.size();

        int lo = 0, hi = 1e9, mid;
        while (lo < hi) {
            mid = lo + (hi-lo+1)/2;
            if (check(mid)) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        cout << lo << '\n';
    }

    return 0;
}
