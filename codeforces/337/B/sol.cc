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

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	long long a, b, c, d, x, y, z;
	cin >> a >> b >> c >> d;
	if (b*c > a*d) {
		y = a*c*b*c;
		x = y-a*c*a*d;
	} else {
		y = a*d*b*d;
		x = y-b*c*b*d;
	}
	z = gcd(x, y);
	cout << x/z << '/' << y/z << '\n';
}
