#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> a, b;

bool check(int x)
{
    if (x > (n-1)/2) return false;

    for (int i = 0; i < x; ++i) {
        b[2*i+1] = a[i];
    }
    for (int i = 0; i < x+1; ++i) {
        b[2*i] = a[i+n-x-1];
    }
    for (int i = 0; i < n-2*x-1; ++i) {
        b[i+2*x+1] = a[i+x];
    }

    int an = 0;
    for (int j = 1; j < n-1; j += 2) {
        if (b[j] < b[j-1] && b[j] < b[j+1]) an++;
    }

    return an >= x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &it: a) cin >> it;
    sort(a.begin(), a.end());

    int lo = 0, hi = (n-1)/2+1;
    while (lo+1 < hi) {
        int mid = lo + (hi-lo)/2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    check(lo);
    cout << lo << '\n';
    for (int i = 0; i < n; ++i) cout << b[i] << ' ';
    cout << '\n';
    return 0;
}

