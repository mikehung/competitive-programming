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

const int NMAX = 200000 + 3;
int A[NMAX], pre[NMAX], a, n;

int32_t main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	int nmin = *min_element(A, A+n), nmax = *max_element(A, A+n);
	if (nmin == nmax) {
		cout << 1LL * nmin * n << '\n';
	} else {
		for (int x = 0; x < 2; ++x) {
			for (int i = 0; i < n; ++i) {
				if (A[i] == nmin)
					pre[i] = 0;
				else {
					int j = (i-1+n)%n;
					pre[i] = pre[j] + 1;
				}
			}
		}
		int k = *max_element(pre, pre+n);
		cout << 1LL * k * (nmin+1) + 1LL * (n-k) * nmin << '\n';
	}
	return 0;
}
// Time: O(), Space: O()
