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
	int n, m, s, g;
	cin >> n >> m;
	set<int> moves;
	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		s = g = -1;
		for (int j = 0; j < m; ++j) {
			if ('S' == str[j])
				s = j;
			else if ('G' == str[j])
				g = j;
		}
		if (s < g) {
			cout << -1 << '\n';
			return 0;
		}
		moves.insert(g-s);
	}
	cout << moves.size() << '\n';
}
