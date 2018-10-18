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
	long long n, k, all, ans = 0;
	cin >> n >> k;
	--n;
	all = k*(k-1)/2;
	if (n > all) {
		puts("-1");
		return 0;
	}
	for (int i = k-1; i >= 1; --i) {
		debug(n, i);
		if (i > n) continue;
		n -= i;
		++ans;
		if (n == 0) {
			cout << ans << '\n';
			return 0;
		}
	}
	puts("-1");
}
