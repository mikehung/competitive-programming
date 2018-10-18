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

int T, R, C;
int sheet[1002][18300];

bool is_formula(const string &s)
{
	return s[0] == '=';
}

int parse_col(const string &col)
{
	int res = 0, base = 1;
	if (col.size() > 1)
		res += 26;
	if (col.size() > 2)
		res += 26 * 26;
	for (int i = col.size()-1; i >= 0; --i) {
		res += (col[i] - 'A') * base;
		base *= 26;
	}
	return res;
}

int parse_row(const string &row)
{
	return stoi(row) - 1;
}

vector<pii> dependency(const string &s)
{
	vector<pii> res;
	string col, row;
	int n = s.size();
	for (int i = 1; i < n; ++i) {
		if (s[i] == '+') {
			res.push_back(make_pair(parse_row(row), parse_col(col)));
			col.clear();
			row.clear();
		} else {
			if (s[i] >= 'A' && s[i] <= 'Z')
				col += s[i];
			else
				row += s[i];
		}
	}
	res.push_back(make_pair(parse_row(row), parse_col(col)));
	return res;
}

int main()
{
	string s;
	int r, c, ur, uc, vr, vc;
	pii u, v;
	cin >> T;
	while (T--) {
		cin >> C >> R;

		map<pii, vector<pii>> G;
		map<pii, int> degree;
		memset(sheet, 0, sizeof(sheet));
		for (r = 0; r < R; ++r) {
			for (c = 0; c < C; ++c) {
				cin >> s;
				if (is_formula(s)) {
					v = make_pair(r, c);
					for (auto & u: dependency(s)) {
						G[u].push_back(v);
						++degree[v];
					}
				} else {
					sheet[r][c] = stoi(s);
				}
			}
		}

		queue<pii> Q;
		for (auto & kv : G) {
			if (degree[kv.first] == 0)
				Q.push(kv.first);
		}
		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
			ur = u.first, uc = u.second;
			for (auto & v : G[u]) {
				vr = v.first, vc = v.second;
				sheet[vr][vc] += sheet[ur][uc];
				if (!--degree[v])
					Q.push(v);
			}
		}

		bool first;
		for (r = 0; r < R; ++r) {
			first = true;
			for (c = 0; c < C; ++c) {
				if (!first)
					cout << ' ';
				first = false;
				cout << sheet[r][c];
			}
			cout << '\n';
		}
	}
	return 0;
}
// Time: O(RC), Space: O(RC)
