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
	ll a, b, ans = 0;
	cin >> a >> b;
	while (a != 1 && b != 1) {
		if (a > b) {
			ans += a / b;
			a = a % b;
		} else {
			ans += b / a;
			b = b % a;
		}
	}
	cout << ans + a + b - 1 << '\n';
	return 0;
}
// Time: O(log(max(a, b))), Space: O(1)
