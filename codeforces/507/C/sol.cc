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
	int H, h, d = 0;
	long long N, n, x, ans = 0;
	char dir[2] = {'L', 'R'};
	string s;
	cin >> H >> N;

	h = H;
	n = N;
	while (h--) {
		x = (1LL << (h));
		if (n <= x)
			s += 'L';
		else
			s += 'R', n -= x;
	}

	for (int i = 0; i < H; ++i) {
		if (s[i] == dir[d]) {
			++ans;
			d = 1 - d;
		} else {
			ans += (1LL << (H-i));
		}
	}
	cout << ans << '\n';

	return 0;
}
// Time: O(H), Space: O(H)
