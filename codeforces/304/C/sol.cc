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
	int n, k;
	cin >> n;
	if (!(n & 1)) {
		puts("-1");
		return 0;
	}
	k = 0;
	for (int i = 0; i < n; ++i) {
		cout << (k + n) % n << ' ';
		--k;
	}
	cout << '\n';

	k = 0;
	for (int i = 0; i < n; ++i) {
		cout << (k + n) % n << ' ';
		k += 2;
	}
	cout << '\n';

	for (int i = 0; i < n; ++i) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
// Time: O(n), Space: O(1)
