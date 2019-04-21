#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    vector<vector<long long>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        v[i] = {b[i] - a[i], i};
    }
    sort(v.begin(), v.end());
    long long an = 0;
    for (long long i = 0; i < n; ++i) {
        long long ai = a[v[i][1]], bi = b[v[i][1]];
        an += ai * i + bi * (n-i-1);
    }
    cout << an << endl;
    return 0;
}
