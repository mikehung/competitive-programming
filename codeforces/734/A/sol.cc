#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cnt = 0;
	string s;
	cin >> n >> s;
	for (char ch : s) {
		if (ch == 'A')
			++cnt;
		else
			--cnt;
	}
	if (cnt > 0)
		cout << "Anton\n";
	else if (cnt == 0)
		cout << "Friendship\n";
	else
		cout << "Danik\n";
	return 0;    
}
