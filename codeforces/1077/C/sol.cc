#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 123;
long long n, a[MAX], mx1, mx2, all;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all += a[i];
        if (a[i] > mx1) {
            mx2 = mx1;
            mx1 = a[i];
        } else if (a[i] > mx2) {
            mx2 = a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        long long big = (a[i] == mx1) ? mx2 : mx1;
        if (all - a[i] - big == big)
            ans.push_back(i+1);
    }
    cout << ans.size() << '\n';
    if (!ans.empty()) {
        for (auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
