#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m-1; ++i) {
        v[i] = v[i+1] - v[i];
    }
    v.pop_back();
    sort(v.begin(), v.end());
    int ans = 0, sz = v.size() - n + 1;
    for (int i = 0; i < sz; ++i) {
        ans += v[i];
    }
    cout << ans << endl;
    return 0;
}
