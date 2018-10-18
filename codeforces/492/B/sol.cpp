#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	double res = max(v.front()-0, l-v.back());
	for (int i = 1; i < n; ++i)
		if (v[i]-v[i-1]>1)
			res = max(res, (v[i]-v[i-1])/2.);
	cout << res << '\n';
	return 0;    
}
