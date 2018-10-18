#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str.size() <= 10)
			cout << str << endl;
		else
			cout << str.front() + to_string(str.size()-2) + str.back() << endl;
	}
	return 0;    
}
