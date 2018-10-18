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

struct Point {
	long long x, y;
};

int n, ans;
long long a, b, c;
Point p1, p2;

int main()
{
	scanf("%lld %lld", &p1.x, &p1.y);
	scanf("%lld %lld", &p2.x, &p2.y);
	scanf("%d", &n);
	bool b1, b2;
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		b1 = a*p1.x + b*p1.y + c > 0LL;
		b2 = a*p2.x + b*p2.y + c > 0LL;
		if (b1 ^ b2)
			++ans;
	}
	printf("%d\n", ans);

	return 0;
}
// Time: O(n), Space: O(1)
