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
	int n, pos;
	map<int, char> m;
	string directions;
	cin >> n >> directions;
	for (int i = 0; i < n; ++i) {
		cin >> pos;
		m[pos] = directions[i];
	}
	int ans = -1;
	for (auto it = m.begin(); next(it) != m.end(); ++it) {
		if (it->second == 'R' && next(it)->second == 'L') {
			if (ans == -1 || ans > (next(it)->first - it->first)/2)
				ans = (next(it)->first - it->first)/2;
		}
	}
	cout << ans << '\n';
}
