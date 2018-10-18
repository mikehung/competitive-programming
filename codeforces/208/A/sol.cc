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

bool is_wub(const string &s, int i)
{
	return i+2 < s.size() && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B';
}

int main() 
{
	string s;
	int i = 0;
	bool word = false;
	cin >> s;
	while (i < s.size()) {
		while (i < s.size() && is_wub(s, i)) i += 3;
		while (i < s.size() && !is_wub(s, i)) {
			cout << s[i++];
			word = true;
		}
		if (word) cout << ' ';
	}
	cout << '\n';
}
