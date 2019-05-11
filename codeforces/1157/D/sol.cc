#include <bits/stdc++.h>

using namespace std;

long long n, k, first, offset;

int find_first()
{
    long long lo = 0, hi = 1e9, mid;
    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        long long x = (mid + mid + k - 1) * k / 2;
        if (x > n) {
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    return lo;
}

bool check_first()
{
    if (first <= 0) return false;
    if (k >= 32) return true;
    long long x = first * ((1<<k) - 1);
    return x >= n;
}

void bye()
{
    cout << "NO\n";
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    first = find_first();
    if (!check_first()) {
        bye();
    }
    vector<long long> a(k);
    for (int i = 0; i < k; ++i) {
        a[i] = first + i;
        n -= a[i];
    }

    int i = 1;
    while (n) {
        while (a[i] == 2ll*a[i-1]) {
            a[i++] += offset;
        }
        long long cnt = k - i;
        long long v = min(n/cnt, 2ll*a[i-1] - a[i]);
        offset += v;
        n -= cnt * v;
        a[i] += offset;
        if (a[i] == 2ll*a[i-1]) {
            ++i;
            continue;
        }
        for (int j = i+1; j < k; ++j) {
            a[j] += offset;
        }
        for (int j = k-1; n; --j, --n) {
            a[j]++;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < k; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
