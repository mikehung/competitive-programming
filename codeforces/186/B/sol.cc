#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define debug(args...)	{ dbg,args; cerr << endl; }
#else
	#define debug(args...)	// do nothing
#endif

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{    
		cerr << v << ' ';
		return *this;
	}
} dbg;

int n, t1, t2, k, a, b;

double H(int a, int b)
{
	return a*t1*(100-k)/100.+b*t2;
}

int main() 
{
	vector<pair<double, int>> res;
	cin >> n >> t1 >> t2 >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		res.push_back(make_pair(max(H(a, b), H(b, a)), n-i));
	}
	sort(res.rbegin(), res.rend());
	for (int i = 0; i < n; ++i) {
		cout << fixed << setprecision(2) << n-res[i].second << ' ' << res[i].first << '\n';
	}
}
