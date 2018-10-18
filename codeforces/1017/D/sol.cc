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
	int n, m, q, mid, n1, n2, x, s1, s2, t1, t2, k, i, j;
	string str;
	unordered_map<int, int> S;
	cin >> n >> m >> q;
	vector<int> V(n);
	for (i = 0; i < n; ++i) {
		cin >> V[i];
	}
	for (i = 0; i < m; ++i) {
		cin >> str;
		++S[stoi(str, 0, 2)];
	}
	n1 = mid = n / 2;
	n2 = n - mid;
	vector<vector<int>> M1(1 << n1, vector<int>(1 << n1));
	vector<vector<int>> M2(1 << n2, vector<int>(1 << n2));
	vector<vector<int>> Wu(1 << n, vector<int>(1 << n));
	vector<map<int, int>> Res(1 << n);
	for (i = 0; i < (1 << n1); ++i) {
		for (j = 0; j < (1 << n1); ++j) {
			x = i ^ j;
			for (int k = 0; k < n1; ++k) {
				if (((x >> k) & 1) == 0) {
					M1[i][j] = V[k];
				}
			}
		}
	}
	for (i = 0; i < (1 << n2); ++i) {
		for (j = 0; j < (1 << n2); ++j) {
			x = i ^ j;
			for (int k = 0; k < n2; ++k) {
				if (((x >> k) & 1) == 0) {
					M2[i][j] = V[mid + k];
				}
			}
		}
	}
	for (i = 0; i < (1 << n); ++i) {
		s1 = (i >> n2) & ((1 << n1) - 1);
		s2 = i & ((1 << n2) - 1);
		for (j = 0; j < (1 << n); ++j) {
			t1 = (j >> n2) & ((1 << n2) - 1);
			t2 = j & ((1 << n2) - 1);
			Wu[i][j] = M1[s1][t1] + M2[s2][t2];
		}
	}
	for (j = 0; j < (1 << n); ++j) {
		for (auto &kv : S) {
			i = kv.first;
			Res[j][Wu[i][j]] += kv.second;
		}
		int pre = -1;
		for (auto &kv : Res[j]) {
			if (pre == -1)
				pre = kv.second;
			else {
				kv.second += pre;
				pre = kv.second;
			}
		}
	}
	for (int _ = 0; _ < q; ++_) {
		cin >> str >> k;
		j = stoi(str, 0, 2);
		auto it = Res[j].lower_bound(k);
		if (it != Res[j].end() && it->first == k)
			cout << it->second << '\n';
		else if (it == Res[j].begin())
			cout << 0 << '\n';
		else
			cout << (--it)->second << '\n';
	}
	return 0;
}
// Time: O(), Space: O()
