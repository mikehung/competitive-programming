#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define debug(args...)            { dbg,args; cerr << endl; }
#else
    #define debug(args...)              // Just strip off all debug tokens
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
	int n, s, imin = INT_MAX, imax = INT_MIN, cnt = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> s;
		v[i] = s;
		imin = min(imin, s);
		imax = max(imax, s);
	}
	for (int i = 0; i < n; ++i) {
		if (v[i] != imin && v[i] != imax)
			++cnt;
	}
	cout << cnt << '\n';
}
