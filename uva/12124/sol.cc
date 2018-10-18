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

typedef pair<long long, long long> Item;
typedef vector<Item> Items;

const int QMAX = 1000000123;
int T, N;
map<string, Items> Components;
vector<string> Types;
vector<long long> MinP;
long long P, Q, ans;

void init()
{
	Components.clear();
	Types.clear();
	MinP.clear();
	ans = -1;
	Q = QMAX;
}

bool bt(int n, long long q, long long p)
{
	if (n == Types.size()) {
		ans = max(ans, q);
		return true;
	}
	if (MinP[n] > p)
		return false;
	for (auto &item : Components[Types[n]]) {
		if (item.first <= p && item.second >= ans)
			if (bt(n+1, min(q, item.second), p-item.first))
				return true;
	}
	return false;
}

int main()
{
	string type, drop;
	long long p, q;
	cin >> T;
	while (T--) {
		cin >> N >> P;
		init();
		for (int i = 0; i < N; ++i) {
			cin >> type >> drop >> p >> q;
			if (p > P) continue;
			Components[type].push_back(make_pair(p, q));
		}
		for (auto &kv : Components) {
			auto &items = kv.second;
			int sz = items.size();
			sort(items.rbegin(), items.rend());
			vector<bool> flag(sz);
			for (int i = 0; i < sz; ++i) {
				for (int j = 0; j < i; ++j) {
					if (items[j].second <= items[i].second)
						flag[j] = true;
				}
			}
			int k = 0;
			for (int i = 0; i < sz; ++i) {
				if (!flag[i])
					items[k++] = items[i];
			}
			items.resize(k);
		}
		for (auto &kv : Components) {
			if (kv.second.size() == 1) {
				auto &item = kv.second[0];
				P -= item.first;
				Q = min(Q, item.second);
			} else {
				Types.push_back(kv.first);
				MinP.push_back(kv.second.back().first);
			}
		}
		for (int i = MinP.size()-2; i >= 0; --i)
			MinP[i] += MinP[i+1];
		for (auto x : MinP)
			cerr << x << ' ';
		cerr << '\n';

		bt(0, Q, P);
		cerr << ans << '\n';
		cout << ans << '\n';
	}
	return 0;
}
// Time: O(), Space: O()
