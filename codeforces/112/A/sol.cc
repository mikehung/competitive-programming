#include <bits/stdc++.h>
using namespace std;

int to(char c) {
	if (c >= 'A' && c <= 'Z')
		return c-'A';
	return c-'a';
}

int main() {
	string s1, s2;
	char c1, c2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); ++i) {
		c1 = to(s1[i]), c2 = to(s2[i]);
		if (c1 == c2) {
			continue;
		} else if (c1 > c2) {
			cout << 1 << '\n';
		} else if (c2 > c1) {
			cout << -1 << '\n';
		}
		return 0;
	}
	cout << 0 << '\n';
	return 0;
}
