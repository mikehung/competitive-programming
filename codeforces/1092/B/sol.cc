#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n/2; ++i) {
        ans += a[2*i+1] - a[2*i];
    }
    cout << ans << '\n';
    return 0;
}
