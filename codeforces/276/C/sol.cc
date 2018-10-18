#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 200005;
ll A[NMAX], P[NMAX];

int main()
{
    ll n, q, l, r, ans = 0;
    cin >> n >> q;
    memset(A, 0, sizeof(A));
    memset(P, 0, sizeof(P));
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> l >> r;
        ++P[l];
        --P[r+1];
    }
    for (int i = 2; i <= n; ++i) {
        P[i] += P[i-1];
    }
    sort(A+1, A+n+1);
    sort(P+1, P+n+1);
    for (int i = 1; i <= n; ++i) {
        ans += A[i] * P[i];
    }
    cout << ans << '\n';

	return 0;
}
// Time: O(nlogn+q), Space: O(n)
