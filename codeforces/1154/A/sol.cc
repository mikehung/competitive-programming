#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v(4);
    for (auto &x: v) cin >> x;
    sort(v.begin(), v.end());
    cout << v[3]-v[0] << ' ' << v[3]-v[1] << ' ' << v[3]-v[2] << endl;
    return 0;
}
