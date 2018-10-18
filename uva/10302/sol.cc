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

const int NMAX =  50005;
ll A[NMAX];

int main()
{
	memset(A, 0, sizeof(A));
	for (ll i = 1; i < NMAX; ++i) {
		A[i] = i*i*i + A[i-1];
	}
	int n;
	while (cin >> n) {
		cout << A[n] << '\n';
	}
	return 0;
}
// Time: O(NMAX), Space: O(NMAX)
