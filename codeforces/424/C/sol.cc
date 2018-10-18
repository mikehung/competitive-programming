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

const int NMAX = 1000006;
int A[NMAX];

int main()
{
	int n, a, ans = 0, div, mod;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		ans ^= a;
		div = n / i;
		mod = n % i;
		if (div & 1) {
			++A[1];
			--A[i];
		}
		++A[1];
		--A[mod+1];
	}
	for (int i = 1; i <= n; ++i) {
		A[i] += A[i-1];
		if (A[i] & 1)
			ans ^= i;
	}
	cout << ans << '\n';

	return 0;
}
// Time: O(), Space: O()
