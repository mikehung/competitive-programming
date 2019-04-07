#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v) cin >> x;
    sort(v.begin(), v.end());
    v[n-1] /= 2;
    cout << accumulate(v.begin(), v.end(), 0) << endl;
    return 0;
}
