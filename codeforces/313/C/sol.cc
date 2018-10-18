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
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int n;
	ll res = 0;
	scanf("%d", &n);
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	sort(a.rbegin(), a.rend());
	for (int i = 1; i < n; ++i)
		a[i] += a[i-1];
	while (n) {
		res += a[n-1];
		n /= 4;
	}
	printf("%lld\n", res);

	return 0;
}
// Time: O(nlogn), Space: O(n)
