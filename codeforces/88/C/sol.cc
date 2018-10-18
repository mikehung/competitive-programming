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

ll gcd(ll a, ll b)
{
	if (!b) return a;
	return gcd(b, a%b);
}

int main()
{
	ll a, b, lcm, cnt = 0, pre = 0, ai = 1, bi = 1;
	cin >> a >> b;
	lcm = a * b / gcd(a, b);
	while (a * ai != lcm || b * bi != lcm) {
		if (a * ai < b * bi) {
			cnt += (a * ai) - pre;
			pre = a * ai;
			++ai;
		} else {
			cnt -= (b * bi) - pre;
			pre = b * bi;
			++bi;
		}
	}
	if (a > b) {
		cnt += lcm - pre;
	} else {
		cnt -= lcm - pre;
	}
	if (cnt > 0)
		puts("Dasha");
	else if (cnt < 0)
		puts("Masha");
	else
		puts("Equal");
	return 0;
}
// Time: O(), Space: O()
