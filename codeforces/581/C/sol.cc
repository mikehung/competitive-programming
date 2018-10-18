#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e5+5;
int n, k, a[MAX], idx[MAX];


bool cmp(int i, int j)
{
    return a[i] % 10 > a[j] % 10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx[i] = i;
    }
    sort(idx, idx+n, cmp);
    for (int i = 0; i < n; ++i) {
        int d = 10 - (a[idx[i]] % 10);
        if (d == 10 || d > k) break;
        a[idx[i]] += d;
        k -= d;
    }
    int rating = k/10;
    for (int i = 0; i < n; ++i)
        rating += a[i]/10;
    cout << min(rating, 10*n) << '\n';

    return 0;
}
