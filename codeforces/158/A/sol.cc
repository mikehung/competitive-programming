#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, cnt = 0, finisher = -1, score = -1;
	cin >> n >> k;
	while (cnt < n) {
		cin >> score;
		if (score == 0 || (finisher != -1 && score < finisher))
			break;
		if (!--k)
			finisher = score;
		++cnt;
	}
	cout << cnt << '\n';
	return 0;    
}
