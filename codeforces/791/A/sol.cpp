#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int a, b, y = 0;
	cin >> a >> b;
	while (a <= b) {
		++y;
		a *= 3;
		b *= 2;
	}
	cout << y << '\n';
	return 0;    
}


