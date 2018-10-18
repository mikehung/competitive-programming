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

long long count(int a, int b)
{
	if (a == 1) return b;
	if (a == 0 || b == 1) return 1;
	long long ret = 0;
	for (int i = 0; i <= a; ++i)
		ret += count(i, b-1);
	return ret;
}

void count2(vector<int> &coin, int n, int i, vector<int> &v, unordered_set<int> &s)
{
	if (v.size() == n) {
		int ret = 0;
		for (int idx : v)
			ret += coin[idx];
		s.insert(ret);
		return;
	}
	if (i == n) {
		return;
	}
	count2(coin, n, i+1, v, s);
	v.push_back(i);
	count2(coin, n, i, v, s);
	v.pop_back();
}

int main() 
{
	int n;
	cin >> n;
	cout << count(n, 4) << '\n';
	vector<int> coin = {1, 5, 10, 50};
	unordered_set<int> s;
	vector<int> v;
	count2(coin, n, 0, v, s);
	cout << s.size() << '\n';
}
