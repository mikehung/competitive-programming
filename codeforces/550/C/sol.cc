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

void dfs(const string &s, string &t, int i, unordered_set<int> &nums)
{
	if (!t.empty())
		nums.insert(stoi(t));
	if (t.size() == 3 || i == s.size())
		return;
	dfs(s, t, i+1, nums);
	t += s[i];
	dfs(s, t, i+1, nums);
	t.pop_back();
}

int main()
{
	string s, t;
	cin >> s;
	unordered_set<int> nums;
	dfs(s, t, 0, nums);
	for (auto num : nums) {
		if (num % 8 == 0) {
			cout << "YES\n" << num << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}
