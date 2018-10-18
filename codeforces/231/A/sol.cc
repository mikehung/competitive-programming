#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, cnt = 0;
	cin >> n;
	while (n--) {
		int c = 0;
		for (int i = 0; i < 3; ++i) {
			cin >> a;
			if (a == 1)
				++c;
		}
		if (c >= 2)
			++cnt;
	}
	cout << cnt << '\n';
	return 0;    
}
