#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	int r = 0;
	while (n) {
		r += n % 10;
		n /= 10;
	}
	return r;
}

int main() {
	string s;
	cin >> s;
	if (s.size() == 1) {
		cout << 0 << '\n';
		return 0;
	}
	int n = 0, cnt = 1;
	for (int i = 0; i < s.size(); ++i) {
		n += s[i]-'0';
	}
	while (n >= 10) {
		n = f(n);
		++cnt;
	}
	cout << cnt << '\n';
	return 0;    
}
