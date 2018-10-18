#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int>> m(5, vector<int>(5));
	int a, b;
	for (int r = 0; r < 5; ++r) {
		for (int c = 0; c < 5; ++c) {
			cin >> m[r][c];
			if (m[r][c]) {
				a = r;
				b = c;
			}
		}
	}
	cout << abs(2-a)+abs(2-b) << '\n';
	return 0;    
}
