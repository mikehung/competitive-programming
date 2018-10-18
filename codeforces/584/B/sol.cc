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
	int M = 1e9+7;
	int n, hit = 0;
	long long all = 1, no = 1;
	cin >> n;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				if (i+j+k == 3)
					++hit;
	while (n--) {
		all = (all * 27) % M;
		no = (no * hit) % M;
	}
	int res = (all-no+M)%M;
	cout << res << '\n';
}
