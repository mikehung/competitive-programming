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

vector<string> keyboard = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

void solve(unordered_map<char, char> &board, string &in)
{
	for (char ch : in)
		cout << board[ch];
	cout << '\n';
}

int main() 
{
	unordered_map<char, char> R, L;
	for (auto &keys : keyboard) {
		for (int i = 0; i < keys.size(); ++i) {
			if (i != 0)
				R[keys[i]] = keys[i-1];
			if (i != keys.size()-1)
				L[keys[i]] = keys[i+1];
		}
	}
	char pos;
	cin >> pos;
	string in;
	cin >> in;
	if (pos == 'R')
		solve(R, in);
	else
		solve(L, in);
}
