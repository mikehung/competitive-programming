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
	int n, a, b, low = -1;
	cin >> n;
	vector<int> A, B;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
		if (i == n/2)
			low = max(a, b);
	}
	if (n == 1) {
		if (A[0] < B[0])
			cout << "1\n0\n";
		else
			cout << "0\n1\n";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (A[i] <= low)
			cout << '1';
		else
			cout << '0';
	}
	cout << '\n';
	for (int i = 0; i < n; ++i) {
		if (B[i] <= low)
			cout << '1';
		else
			cout << '0';
	}
	cout << '\n';

	return 0;
}
// Time: O(), Space: O()
