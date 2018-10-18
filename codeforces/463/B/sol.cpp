#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, pre_h = 0, cur_h = 0, engry = 0, cost = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cur_h;
		int e = pre_h - cur_h;
		if (e >= 0) {
			engry += e;
		} else {
			if (engry >= -e) {
				engry += e;
			} else {
				cost += -e-engry;
				engry = 0;
			}
		}
		pre_h = cur_h;
	}
	cout << cost << '\n';
	return 0;    
}
