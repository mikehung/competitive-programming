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
	int n, m, h, lo, hi;
	cin >> n;
	vector<int> heights(n);
	for (int i = 0; i < n; ++i)
		cin >> heights[i];
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> h;
		lo = hi = -1;
		auto lit = lower_bound(heights.begin(), heights.end(), h);
		auto uit = upper_bound(heights.begin(), heights.end(), h);
		// debug(i+1, ": ", h, distance(heights.begin(), lit), distance(heights.begin(), uit));
		if (lit == heights.end())
			lo = heights.back();
		else if (lit != heights.begin())
			lo = *--lit;
		if (uit != heights.end())
			hi = *uit;
		if (lo == -1)
			cout << 'X';
		else
			cout << lo;
		cout << ' ';
		if (hi == -1)
			cout << 'X';
		else
			cout << hi;
		cout << '\n';
	}
}
