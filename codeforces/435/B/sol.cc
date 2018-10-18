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
	string s;
	char max_ch;
	int k, max_idx;
	cin >> s >> k;
	for (int i = 0; i < s.size() && k; ++i) {
		max_idx = i;
		for (int j = i+1; j-i <= k && j < s.size(); ++j) {
			if (s[j]-'0' > s[max_idx]-'0') {
				max_idx = j;
			}
		}
		if (max_idx != i) {
			k -= max_idx-i;
			max_ch = s[max_idx];
			for (size_t j = max_idx; j > i; --j)
				s[j] = s[j-1];
			s[i] = max_ch;
		}
	}
	cout << s << '\n';
}
// Time: O(n^2), Space: O(n), n = s.size()
