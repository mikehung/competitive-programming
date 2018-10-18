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

bool cmp(const pii &p1, const pii &p2)
{
	return p1.second-p1.first > p2.second-p2.first;
}

int main()
{
	int n, k, a, b, ans = 0;
	cin >> n >> k;
	vector<pii> A(n);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		A[i].first = a;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b;
		A[i].second = b;
	}
	sort(A.begin(), A.end(), cmp);
	for (int i = 0; i < n; ++i) {
		if (A[i].second > A[i].first) {
			ans += A[i].first;
			--k;
		} else if (k > 0) {
			ans += A[i].first;
			--k;
		} else {
			ans += A[i].second;
		}
	}
	cout << ans << '\n';
	return 0;
}
// Time: O(), Space: O()
