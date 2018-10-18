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
	int ok = 0, left = 0;
	string s;
	cin >> s;
	for (char ch : s) {
		if (ch == '(')
			++left;
		else {
			if (left > 0) {
				++ok;
				--left;
			}
		}
	}
	cout << ok*2 << '\n';
}
