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
	string s;
	cin >> s;
	int ans = 1, e = 2, b = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i != s.size()-1)
			ans += e;
		e *= 2;
		b *= 2;
		if (s[i] == '7')
			b += 1;
	}
	cout << ans + b << '\n';
}
