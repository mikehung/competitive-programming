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

unordered_set<ll> primes;

int get_peg(const vector<ll> &v, ll n)
{
	for (int i = 0; i < v.size(); ++i) {
		if (!v[i]) return i;
		if (primes.count((v[i]+n))) return i;
	}
	return -1;
}

int main()
{
	for (int i = 1; i < 1234567; ++i)
		primes.insert(i*i);

	int T, N, peg;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		vector<ll> v(N);
		ll n = 1;
		while ((peg = get_peg(v, n)) != -1) {
			v[peg] = n++;
		}
		printf("%lld\n", n-1);
	}

	return 0;
}
// Time: O(N), Space: O(N)
