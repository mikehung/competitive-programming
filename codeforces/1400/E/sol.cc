#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> a;

int calc(int l, int r)
{
    if (l+1 > r) return 0;
    int mn = l;
    for (int i = l+1; i < r; ++i) {
        if (a[i] < a[mn]) mn = i;
    }
    int x = a[mn];
    for (int i = l; i < r; ++i) {
        a[i] -= x;
    }
    return min(r-l, calc(l, mn) + calc(mn+1, r) + x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for (auto &it: a) cin >> it;
    cout << calc(0, n) << '\n';
    return 0;
}
