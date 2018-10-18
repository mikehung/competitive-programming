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
	long long ta, tb;
	while (cin >> ta >> tb) {
		if (ta == 1 && tb == 1) {
			break;
		}
		string ans;
		long long la = 0, lb = 1, ha = 1, hb = 0, ma = 1, mb = 1;
		while (true) {
			ma = la + ha;
			mb = lb + hb;
			if (ma == ta && mb == tb) {
				break;
			} else if (ma*tb < ta*mb) {
				ans += "R";
				la = ma;
				lb = mb;
			} else {
				ans += "L";
				ha = ma;
				hb = mb;
			}
		}
		cout << ans << '\n';
	}
}
