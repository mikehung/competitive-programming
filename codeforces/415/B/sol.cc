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
	long long n, a, b, x, v, lo, hi, mid;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		v = x * a / b;
		lo = 0, hi = x;
		while (lo < hi) {
			mid = lo + (hi-lo) / 2;
			if (mid * a / b >= v)
				hi = mid;
			else
				lo = mid+1;
		}
		cout << x-lo << ' ';
	}
	cout << '\n';
}
