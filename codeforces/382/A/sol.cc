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
	int pos = s.find('|');
	string a = s.substr(0, pos), b = s.substr(pos+1);
	for (auto ch : r) {
		if (a.size() > b.size())
			b += ch;
		else
			a += ch;
	}
	if (a.size() != b.size())
		cout << "Impossible\n";
	else
		cout << a << '|' << b << '\n';
}
