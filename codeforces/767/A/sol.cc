#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define debug(args...)            { cerr << "ln " << __LINE__ << ": "; dbg,args; cerr << endl; }
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
	int n, sz, pos;
	cin >> n;
	pos = n;
	vector<bool> ok(n+1);
	for (int i = 0; i < n; ++i) {
		cin >> sz;
		ok[sz] = true;
		while (ok[pos]) {
			cout << pos-- << ' ';
		}
		cout << '\n';
	}
}
