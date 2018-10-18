#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define debug(args...)	{ dbg,args; cerr << endl; }
#else
	#define debug(args...)	// do nothing
#endif

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr << v << ' ';
		return *this;
	}
} dbg;

int main()
{
	int n, l, r, x, amin, amax;
	long long total, cnt = 0;
	cin >> n >> l >> r >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int ps = 0; ps < (1<<n); ++ps) {
		if (!(ps & (ps-1))) continue;
		amin = INT_MAX;
		amax = INT_MIN;
		total = 0;
		for (int i = 0; i < n; ++i) {
			if (ps & (1<<i)) {
				total += a[i];
				amin = min(amin, a[i]);
				amax = max(amax, a[i]);
			}
		}
		if (l <= total && total <= r && amax-amin >= x)
			++cnt;
	}
	cout << cnt << '\n';
}
