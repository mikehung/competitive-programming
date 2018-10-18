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

unordered_map<ll, ll> cache;
vector<ll> coef;

ll f(ll x)
{
	if (cache.count(x))
		return cache[x];
	ll res = coef.back(), y = x;
	for (ll i = coef.size()-2; i >= 0; --i) {
		res += coef[i] * y;
		y *= x;
	}
	return cache[x] = res;
}


int main()
{
	istringstream iss;
	string s;
	ll c, x;
	while (getline(cin, s)) {
		cache.clear();
		coef.clear();

		iss.clear();
		iss.str(s);
		while (iss >> c)
			coef.push_back(c);

		getline(cin, s);
		iss.clear();
		iss.str(s);
		bool first = true;
		while (iss >> x) {
			if (!first)
				cout << ' ';
			first = false;
			cout << f(x);
		}
		cout << '\n';
	}
	return 0;
}
// Time: O(), Space: O()
