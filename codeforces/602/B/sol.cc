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
	int n, i = 0, j = 0, imin, imax, x, ans = 0;
	cin >> n;
	for (; j < n; ++j) {
		cin >> x;
		if (!j) {
			imin = imax = x;
		} else {
			imin = min(imin, x);
			imax = max(imax, x);
			if (imax - imin > 1) {
				ans = max(ans, j-i);
				i = j;
				imin = imax = x;
			}
		}
	}
	debug(i, j);
	ans = max(ans, j-i);
	cout << ans << '\n';
}
