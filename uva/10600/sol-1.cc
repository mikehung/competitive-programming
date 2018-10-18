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

static const int X = 123;
int T, N, M, u, v, c, s, d;
int P[X];
int R[X];
vector<tuple<int, int, int>> E(X*X);

void init()
{
	for (int i = 1; i < N+1; ++i) {
		P[i] = i;
		R[i] = 0;
	}
}

int find(int x)
{
	if (x != P[x])
		P[x] = find(P[x]);
	return P[x];
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	P[x] = y;
}

int main() 
{
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; ++i) {
			cin >> u >> v >> c;
			E[i] = make_tuple(c, u, v);
		}
		sort(E.begin(), E.begin()+M);
		init();
		map<int, vector<pair<int, int>>> MST;
		int cnt = 0, cost = 0;
		int e = 0;
		while (cnt != N-1) {
			tie(c, u, v) = E[e++];
			if (find(u) != find(v)) {
				++cnt;
				cost += c;
				merge(u, v);
				MST[u].push_back(make_pair(v, c));
				MST[v].push_back(make_pair(u, c));
			}
		}
		int maxc, cost2 = INT_MAX, cost_now;
		while (e < M) {
			tie(c, s, d) = E[e++];
			debug("xxx", s, d);
			maxc = 0, cost_now = cost + c;
			int p = 0;
			while (s != d) {
				for (auto &par : MST[s]) {
					tie(u, c) = par;
					if (u == p) continue;
					if (c > maxc)
						maxc = c;
					p = s;
					s = u;
				}
			}
			cost_now -= maxc;
			if (cost2 > cost_now)
				cost2 = cost_now;
		}
		cout << cost << ' ' << cost2 << '\n';
	}
}
