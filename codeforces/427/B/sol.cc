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

int main()
{
	int n, t, c;
	cin >> n >> t >> c;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int i = 0, j = 0, res = 0;
	do {
		while (j < n && a[j] <= t)
			++j;
		if (j-i >= c)
			res += j-i-c+1;
		++j;
		i = j;
	} while (j < n);
	cout << res << '\n';

	return 0;
}
// Time: O(n), Space: O(n)
