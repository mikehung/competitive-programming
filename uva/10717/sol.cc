#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
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

void get_factor(ll n, map<ll, ll> &factor)
{
	while (n % 2 == 0) {
		++factor[2];
		n /= 2;
	}
	for (ll i = 3; i * i <= n; ++i) {
		while (n % i == 0) {
			++factor[i];
			n /= i;
		}
	}
	if (n > 2)
		++factor[n];
}

void get_four_coins(int n, vector<int> &prefix, vector<vector<int>> &all)
{
	if (prefix.size() == 4) {
		all.push_back(prefix);
		return;
	}
	if (n < 0) {
		return;
	}
	prefix.push_back(n);
	get_four_coins(n-1, prefix, all);
	prefix.pop_back();
	get_four_coins(n-1, prefix, all);
}

int main()
{
	int n, t;
	while (cin >> n >> t) {
		if (n == 0 && t == 0) break;
		vector<ll> coins(n);
		vector<map<ll, ll>> factors(n);
		for (int i = 0; i < n; ++i) {
			cin >> coins[i];
			get_factor(coins[i], factors[i]);
		}
		ll table, lcm, a, b;
		vector<vector<int>> all;
		vector<int> prefix;
		map<ll, ll> factor;
		get_four_coins(n-1, prefix, all);
		for (int i = 0; i < t; ++i) {
			cin >> table;
			a = 0;
			b = LLONG_MAX;
			for (auto select : all) {
				factor.clear();
				for (auto coin : select) {
					for (auto &kv : factors[coin]) {
						factor[kv.first] = max(factor[kv.first], kv.second);
					}
				}
				lcm = 1;
				for (auto &kv : factor) {
					lcm *= (ll) pow(kv.first, kv.second);
				}
				if (table % lcm == 0) {
					a = table;
					b = table;
				} else {
					ll x = table / lcm;
					a = max(a, lcm * x);
					b = min(b, lcm * (x+1));
				}
			}
			cout << a << ' ' << b << '\n';
		}
	}

	return 0;
}
// Time: O(), Space: O()
