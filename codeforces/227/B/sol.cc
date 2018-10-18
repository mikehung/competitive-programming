#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a, query;
	cin >> n;
	vector<int> cnt(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		cnt[a] = i;
	}
	long long cnt_beg = 0, cnt_end = 0;
	cin >> m;
	while (m--) {
		cin >> query;
		cnt_beg += cnt[query];
		cnt_end += n+1-cnt[query];
	}
	cout << cnt_beg << ' ' << cnt_end << '\n';
	return 0;
}
