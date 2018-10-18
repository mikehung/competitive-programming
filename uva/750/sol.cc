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

const int N = 8;
int sr, sc;
vector<int> res;
set<vector<int>> ans;
bool col[N], row[N], diag1[2*N], diag2[2*N];

void init()
{
	res.clear();
	res.resize(N);
	ans.clear();
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	memset(diag1, 0, sizeof(diag1));
	memset(diag2, 0, sizeof(diag2));
}

void fill(int r, int c)
{
	row[r] = col[c] = diag1[r+c] = diag2[r-c+N-1] = 1;
	res[c] = r;
}

void reset(int r, int c)
{
	row[r] = col[c] = diag1[r+c] = diag2[r-c+N-1] = 0;
	res[c] = 0;
}

bool valid(int r, int c)
{
	return !row[r] && !col[c] && !diag1[r+c] && !diag2[r-c+N-1];
}

void bt(int i)
{
	if (i == 8) {
		ans.insert(res);
		return;
	}
	int c = (sc + i) % N;
	for (int r = 0; r < N; ++r) {
		if (valid(r, c)) {
			fill(r, c);
			bt(i+1);
			reset(r, c);
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		if (t != 1) printf("\n");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		cin >> sr >> sc;

		init();
		--sr, --sc;
		fill(sr, sc);
		bt(1);

		int i = 1;
		for (auto &res : ans) {
			if (i != 1) printf("\n");
			printf("%2d      ", i++);
			for (int j = 0; j < N; ++j) {
				if (j) printf(" ");
				printf("%d", res[j]+1);
			}
		}
		printf("\n");
	}
	return 0;
}
// Time: O(), Space: O()
