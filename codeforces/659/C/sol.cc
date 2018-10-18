#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
	#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
	#define dbg(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int n, m, x;
	cin >> n >> m;
	set<int> s;
	vector<int> got;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		s.insert(x);
	}
	for (int i = 1; m >= 0; ++i) {
		if (s.count(i))
			continue;
		got.push_back(i);
		m -= i;
	}
	cout << got.size()-1 << '\n';
	for (int i = 0; i < got.size()-1; ++i)
		cout << got[i] << ' ';
	cout << '\n';

	return 0;
}
// Time: O(n+sqrt(m)*logn), Space: O(n)
