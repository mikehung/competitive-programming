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
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        reverse(a.begin(), a.end());
        for (auto x: a) cout << x << ' '; cout << '\n';
    }
    return 0;
}
