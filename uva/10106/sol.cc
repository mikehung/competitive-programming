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

int main() 
{
	string s, t;
	while (cin >> s >> t) {
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		vector<int> v(s.size()+t.size());	
		for (int si = 0; si < s.size(); ++si) {
			if (s[si] == '0') continue;
			for (int ti = 0; ti < t.size(); ++ti) {
				v[si+ti] += (s[si]-'0') * (t[ti]-'0');
			}
		}
		for (int i = 0; i < v.size()-1; ++i) {
			v[i+1] += v[i] / 10;
			v[i] %= 10;
		}
		int i = v.size()-1;
		while (i > 0 && v[i] == 0) --i;
		for (; i >= 0; --i) {
			cout << v[i];
		}
		cout << '\n';
	}
}
