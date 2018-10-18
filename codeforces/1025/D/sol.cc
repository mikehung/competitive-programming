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
	#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
	#define dbg(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 705;
int n;
int a[NMAX];
bool gcd[NMAX][NMAX], dp[NMAX][NMAX];

int main()
{
	cin >> n;
	int i, j, l, r, k, ok1, ok2;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	for (i = 0; i < n; ++i)
		for (j = i; j < n; ++j)
			gcd[i][j] = __gcd(a[i], a[j]) > 1;

	for (i = 0; i < n; ++i)
		dp[i][i] = 1;
	for (i = 0; i < n-1; ++i)
		dp[i][i+1] = gcd[i][i+1];
	for (l = 2; l < n; ++l) {
		for (i = 0; i+l < n; ++i) {
			j = i + l;
			for (r = i; r <= j; ++r) {
				ok1 = 0, ok2 = 0;
				if ((r == i || dp[i][r-1]) && (r == j || dp[r+1][j])) {
					ok1 = r == i;
					for (k = i; k <= r-1; ++k)
						ok1 |= gcd[k][r];
					ok2 = r == j;
					for (k = r+1; k <= j; ++k)
						ok2 |= gcd[r][k];
					if (ok1 && ok2) {
						dbg("i: %d, j: %d, r: %d\n", i, j, r);
						dp[i][j] = 1;
						break;
					}
				}
			}
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j)
			dbg("%d ", gcd[i][j]);
		dbg("\n");
	}
	dbg("\n");
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j)
			dbg("%d ", dp[i][j]);
		dbg("\n");
	}
	if (dp[0][n-1])
		puts("Yes");
	else
		puts("No");
	return 0;
}
// Time: O(), Space: O()
