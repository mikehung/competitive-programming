#ifdef DEBUG
#include "../../testlib/testlib.h"
#endif
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, len = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
	int j = 0;
	println("a:", a);
    for (int i = 0; i < n; ++i) {
		while (j < n && a[j] <= 2*a[i]) ++j;
        len = max(len, j-i);
		println(i, j);
    }
    cout << n - len << '\n';
}
