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
	int n, m, c;
	while (cin >> n >> m >> c && n != 0) {
		if (c == 1)
			cout << (m/2-3)*(n/2-3) + ((m-1)/2-3)*((n-1)/2-3) << '\n';
		else
			cout << ((m-1)/2-3)*(n/2-3) + ((m/2-3)*((n-1)/2-3)) << '\n';
	}
}
