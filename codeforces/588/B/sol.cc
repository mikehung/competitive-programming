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

bool prime(ll n)
{
	if (n == 2) return true;
	if (n < 2) return false;
	for (int i = 3; i*i <= n; i += 2) {
		if (n % 3 == 0) return false;
	}
	return true;
}

int main()
{
	ll n, ans = 1;
	cin >> n;
	if (n % 2 == 0) {
		ans *= 2;
		while (n % 2 == 0) n /= 2;
	}
	for (int i = 3; n != 1; i += 2) {
		if (n % i == 0) {
			ans *= i;
			while (n % i == 0) n /= i;
		}
	}
	cout << ans << '\n';

	return 0;
}
// Time: O(), Space: O()
