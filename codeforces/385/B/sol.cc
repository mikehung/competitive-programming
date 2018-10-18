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
	cin >> s;
	vector<int> indices;
	for (int i = 0; i < s.size(); ++i) {
		if (s.substr(i, 4) == "bear") {
			indices.push_back(i);
		}
	}
	if (indices.empty()) {
		cout << 0 << '\n';
		return 0;
	}
	int res = 0, j = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i > indices[j]) {
			++j;
		}
		if (j == indices.size())
			break;
		res += s.size() - (indices[j]+3);
	}
	cout << res << '\n';
}
