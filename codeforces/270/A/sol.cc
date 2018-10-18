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
	unordered_set<int> angles;
	for (int i = 3; i <= 700; ++i) {
		if ((i-2)*180 % i) continue;
		angles.insert((i-2) * 180 / i);
	}
	int n, angle;
	cin >> n;
	while (n--) {
		cin >> angle;
		if (angles.find(angle) == angles.end())
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
