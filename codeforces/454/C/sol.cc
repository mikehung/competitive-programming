#include <iostream>
#include <iomanip>
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
	int m, n;
	cin >> m >> n;
	double sum = 0;
	for (int i = 1; i < m; ++i) {
		sum += pow(double(m-i)/m, n);
	}
	cout << fixed << setprecision(12) << m - sum << '\n';

	return 0;
}
// Time: O(), Space: O()
