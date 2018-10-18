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

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	string s;
	cin >> s;
	int n = s.size(), ans = 0, j = 0;
	s += s;
	for (int i = 1; i < 2*n; ++i) {
		ans = max(ans, i-j);
		if (s[i] == s[i-1]) {
			j = i;
		}
	}
	cout << min(ans, n) << '\n';
	return 0;
}
// Time: O(n), Space: O(1)
