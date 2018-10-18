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
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

string byte_srt = "127";
string short_str = "32767";
string int_str = "2147483647";
string long_str = "9223372036854775807";

bool bigger(const string &s, const string &t)
{
	if (s.size() > t.size())
		return true;
	if (s.size() < t.size())
		return false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == t[i]) continue;
		if (s[i]-'0' > t[i]-'0') return true;
		else return false;
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	if (bigger(s, long_str)) {
		puts("BigInteger");
	} else if (bigger(s, int_str)) {
		puts("long");
	} else if (bigger(s, short_str)) {
		puts("int");
	} else if (bigger(s, byte_srt)) {
		puts("short");
	} else {
		puts("byte");
	}
	return 0;
}
// Time: O(), Space: O()
