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

int main()
{
	int x, y, a, b, c, d;
	cin >> x >> y >> a >> b >> c >> d;
	if (c < d) swap(c, d);
	if ((x >= a && max(x, y-b) >= c && min(x, y-b) >= d) ||
		(x >= b && max(x, y-a) >= c && min(x, y-a) >= d) ||
		(y >= a && max(y, x-b) >= c && min(y, x-b) >= d) ||
		(y >= b && max(y, x-a) >= c && min(y, x-a) >= d))
		puts("YES");
	else
		puts("NO");
	return 0;
}
// Time: O(1), Space: O(1)
