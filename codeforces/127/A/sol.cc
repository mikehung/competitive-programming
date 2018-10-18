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
	int n, k, x1, y1, x2, y2;
	cin >> n >> k;
	double distance = 0;
	cin >> x1 >> y1;
	--n;
	while (n--) {
		cin >> x2 >> y2;
		distance += sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		x1 = x2;
		y1 = y2;
	}
	cout << fixed << setprecision(9) << distance / 50 * k << '\n';
}
