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

string s;
const int NMAX = 1000 + 3;
int cache[NMAX][NMAX];

int solve(int i, int j)
{
	if (i >= j) return 0;
	if (cache[i][j] == -1) {
		int res = solve(i+1, j-1) + int(s[i] != s[j]);
		res = min(res, solve(i, j-1)+1);
		res = min(res, solve(i+1, j)+1);
		cache[i][j] = res;
	}
	return cache[i][j];
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		memset(cache, -1, sizeof(cache));
		cin >> s;
		printf("Case %d: %d\n", t, solve(0, s.size()-1));
	}
	return 0;
}
// Time: O(n^2), Space: O(n^2)
