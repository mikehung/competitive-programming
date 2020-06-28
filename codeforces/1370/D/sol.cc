#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;

bool check(int x)
{
    vector<bool> b(n, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= x) b[i] = true;
    }
    
    if (b[0] == 1) {
        int i = 0;
        while (b[i]) ++i;
        for (int j = 1; i-j >= 0; ++j) {
            if (j % 2 == 0) b[i-j] = false;
        }
    }
    for (int i = 0; i < n; ++i) if (b[i]) {
        int j = 0;
        while (i+j < n && b[i+j]) {
            if (j % 2) b[i+j] = false;
            ++j;
        }
        i += j-1;
    }

    int cnt = 0;
    bool plus = true;
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            ++cnt;
            plus = true;
        } else {
            if (plus) ++cnt;
            plus = false;
        }
    }

    return cnt >= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int lo = 1, hi = 1e9+11, mid;
    while (lo < hi) {
        mid = lo + (hi-lo)/2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    cout << lo << '\n';
    return 0;
}
