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

const int NMAX = 100005;
int cnt[NMAX];
long long dp[NMAX];

int main()
{
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		++cnt[a];
	}
	dp[1] = cnt[1];
	for (int i = 2; i < NMAX; ++i)
		dp[i] = max(dp[i-1], 1LL * i * cnt[i] + dp[i-2]);
	cout << dp[NMAX-1] << '\n';

	return 0;
}
// Time: O(), Space: O()
