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
	int n;
	string directions;
	cin >> n >> directions;
	vector<int> pos(n);
	for (int i = 0; i < n; ++i)
		cin >> pos[i];
	int ans = -1;
	for (int i = 0; i < n-1; ++i) {
		if (directions[i] == 'R' && directions[i+1] == 'L') {
			if (ans == -1 || ans > (pos[i+1] - pos[i])/2)
				ans = (pos[i+1] - pos[i])/2;
		}
	}
	cout << ans << '\n';
}
