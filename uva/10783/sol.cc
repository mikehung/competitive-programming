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
	int T, a, b, ans;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> a >> b;
		if (a == b)
			ans = 0;
		else {
			if ((a % 2) == 0)
				++a;
			if ((b % 2) == 0)
				--b;
			ans = (a+b) * (1+(b-a)/2) / 2;
		}
		printf("Case %d: %d\n", i, ans);
	}

	return 0;
}
// Time: O(), Space: O()
