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
	int a, b, c, d, e, f, ans = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for (int i = 0; i < b; ++i)
		ans += (a+i)*2+1;
	for (int i = 0; i < c; ++i)
		ans += (d+i)*2+1;
	cout << ans << '\n';
	return 0;
}
// Time: O(), Space: O()
