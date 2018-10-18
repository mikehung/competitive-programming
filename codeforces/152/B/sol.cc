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

int get_len(int x, int n, int dx)
{
	if (dx == 0)
		return -1;
	else if (dx < 0)
		return x;
	else
		return n-x;
}

int main() 
{
	int n, m, x, y, k, dx, dy, lx, ly, step;
	long long steps = 0;
	cin >> n >> m >> x >> y >> k;
	--n, --m, --x, --y;
	while (k--) {
		cin >> dx >> dy;
		lx = get_len(x, n, dx);
		ly = get_len(y, m, dy);
		if (lx == -1)
			step = ly/abs(dy);
		else if (ly == -1)
			step = lx/abs(dx);
		else
			step = min(lx/abs(dx), ly/abs(dy));
		x += step * dx;
		y += step * dy;
		steps += step;
	}
	cout << steps << '\n';
}
