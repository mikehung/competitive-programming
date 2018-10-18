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
	int n, a, b, ans = 0, end;
	cin >> n;
	vector<pair<int, int>> history(n);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		history[i] = make_pair(a, b);
	}
	sort(history.begin(), history.end());
	end = history[0].second;
	for (int i = 1; i < n; ++i) {
		if (history[i].second < end) {
			++ans;
		}
		end = max(end, history[i].second);
	}
	cout << ans << '\n';
	return 0;
}
// Time: O(nlogn), Space: O(n)
