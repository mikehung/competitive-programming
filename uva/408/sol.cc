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

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() 
{
	int a, b;
	while (cin >> a >> b) {
		int x = gcd(a, b);
		if (x == 1)
			printf("%10d%10d    %s\n\n", a, b, "Good Choice");
		else
			printf("%10d%10d    %s\n\n", a, b, "Bad Choice");
	}
}
