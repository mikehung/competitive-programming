#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
	#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
	#define dbg(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	string s, t;
	cin >> s >> t;
	char ch;
	int yay = 0, whoops = 0;
	unordered_map<char, int> m;
	vector<bool> used(t.size());
	for (char ch : s)
		++m[ch];
	for (int i = 0; i < t.size(); ++i) {
		ch = t[i];
		if (m[ch]) {
			++yay;
			--m[ch];
			used[i] = true;
		}
	}
	for (int i = 0; i < t.size(); ++i) {
		if (!used[i]) {
			ch = isupper(t[i]) ? tolower(t[i]) : toupper(t[i]);
			if (m[ch]) {
				++whoops;
				--m[ch];
			}
		}
	}
	cout << yay << ' ' << whoops << '\n';

	return 0;
}
// Time: O(ssz+tsz), Space: O(ssz+tsz), ssz = s.size(), tsz = t.size()
