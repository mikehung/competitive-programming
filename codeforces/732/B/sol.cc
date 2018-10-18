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
	int n, k, x, cnt = 0;
	cin >> n >> k;
	vector<int> a(n+1);
	a[0] = k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		x = k-a[i]-a[i+1];
		if (x > 0) {
			cnt += x;
			a[i+1] += x;
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}
