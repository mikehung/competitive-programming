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
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;
vector<pii> a(N);

int main()
{
	int sum, limit;
	vector<int> ans;
	scanf("%d %d", &sum, &limit);
	for (int i = 1; i <= limit; ++i) {
		a[i] = make_pair(i & ~(i&(i-1)), i);
	}
	sort(a.begin()+1, a.begin()+limit+1);
	for (int i = limit; i >= 1; --i) {
		if (a[i].first <= sum) {
			sum -= a[i].first;
			ans.push_back(a[i].second);
			if (!sum) {
				cout << ans.size() << '\n';
				for (int x : ans)
					printf("%d ", x);
				return 0;
			}
		}
	}
	puts("-1");

	return 0;
}
// Time: O(nlogn), Space: O(n)
