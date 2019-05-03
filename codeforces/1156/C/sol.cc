#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, z;
    cin >> n >> z;
    vector<long long> a(n);
    for (auto &v: a) cin >> v;
    sort(a.begin(), a.end());
    int an = 0;
    for (int i = 0, j = n/2; i < n/2 && j < n; ++i, ++j) {
        while (j < n && (a[j]-a[i] < z)) ++j;
        if (j < n) an++;
    }
    cout << an << endl;
    return 0;
}
