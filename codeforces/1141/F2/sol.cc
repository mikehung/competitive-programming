#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &v: a) cin >> v;

	map<int, vector<pair<int, int>>> segs;
	for (int r = 0; r < n; ++r) {
		int sum = 0;
		for (int l = r; l >= 0; --l) {
			sum += a[l];
			segs[sum].push_back({l, r});
		}
	}

    vector<pair<int, int>> best;
    for (auto &kv: segs) {
        vector<pair<int, int>> curr;
        for (auto &kv2: kv.second) {
            int l = kv2.first, r = kv2.second;
            if (curr.empty() || l > curr.back().second) curr.push_back({l, r});
        }
        if (curr.size() > best.size()) swap(best, curr);
    }

    cout << best.size() << endl;
    for (auto &kv: best) cout << kv.first+1 << ' ' << kv.second+1 << '\n';
    return 0;
}
