#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, j, cnt = 0;
	cin >> n >> k;
	while (n--) {
		cin >> j;
		if (j > k)
			cnt += 2;
		else
			cnt += 1;
	}
	cout << cnt << '\n';
	return 0;    
}
