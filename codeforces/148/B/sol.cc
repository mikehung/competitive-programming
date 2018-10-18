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
	int vp, vd, t, f, c, cnt = 0, diff;
	double pos, T;
	cin >> vp >> vd >> t >> f >> c;
	if (vp >= vd) {
		cout << 0 << '\n';
		return 0;
	}
	diff = vd - vp;
	pos = t * vp;
	while (true) {
		T = pos / diff;
		if (pos + T*vp >= c)
			break;
		++cnt;
		pos += (2*T+f)*vp;
	}
	cout << cnt << '\n';
}
