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
	int n, a, b, x = 0, flag = 1;
	string ans;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (abs(x+a) <= 500) {
			x += a;
			ans += 'A';
		} else if (abs(x-b) <= 500) {
			x -= b;
			ans += 'G';
		} else {
			flag = 0;
			break;
		}
	}
	if (flag) {
		puts(ans.c_str());
	} else {
		puts("-1");
	}
}
