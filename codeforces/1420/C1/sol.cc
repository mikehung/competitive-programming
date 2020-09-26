#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll calc(const vector<int> &a)
{
    int n = a.size(), i = 0, j = 0;
    ll an = 0;
    while (i < n) {
        while (i+1 < n && a[i+1] > a[i]) ++i;
        j = i+1;
        while (j+1 < n && a[j+1] < a[j]) ++j;

        if (j < n-1) an += a[i] - a[j];
        else an += a[i];
        i = j+1;
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        cout << calc(a) << '\n';
        while (q--) {
        }
    }
    return 0;
}
