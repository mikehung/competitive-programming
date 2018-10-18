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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n && k; ++i) {
		if (a[i] < 0) {
			a[i] *= -1;
			--k;
		} else {
			if (k % 2) {
				if (i == 0 || a[i] < a[i-1])
					a[i] *= -1;
				else
					a[i-1] *= -1;
			}
			k = 0;
		}
	}
	debug(k);
	if (k % 2)
		a[n-1] *= -1;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += a[i];
	}
	cout << res << '\n';
}
