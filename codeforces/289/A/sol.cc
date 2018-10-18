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
	int n, k, l, r;
	long long cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		cnt = (cnt + (r-l+1) % k) % k;
	}
	if (cnt != 0)
		cnt = k - cnt;
	cout << cnt << '\n';
}
