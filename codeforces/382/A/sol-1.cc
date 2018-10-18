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
	string s, r;
	cin >> s >> r;
	int cnt = 0, diff = 1;
	for (auto ch : s) {
		if (ch == '|')
			diff *= -1;
		else
			cnt += diff;
	}
	int even = r.size()-abs(cnt);
	if (abs(cnt) > r.size() || even % 2) {
		cout << "Impossible\n";
		return 0;
	}
	even /= 2;
	int i;
	if (cnt > 0)
		i = r.size()-cnt-even;
	else
		i = -cnt+even;
	r.insert(i, s);
	cout << r << '\n';
}
