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

struct Vertex {
	int x, y;
	Vertex() : x(0), y(0) {}
	Vertex(int a, int b) : x(a), y(b) {}
};

struct Edge {
	int l, u, v;
	Edge() : l(0), u(0), v(0) {}
	Edge(int a, int b, int c) : l(a), u(b), v(c) {}
};

int X = 755;
int groups;
vector<Vertex> V(X);
vector<Edge> E(X*X/2);
vector<int> P(X);
vector<int> R(X);

bool cmp(const Edge &e1, const Edge &e2)
{
	return e1.l < e2.l;
}

int find(int x)
{
	if (P[x] != x)
		P[x] = find(P[x]);
	return P[x];
}

void link(int x, int y)
{
	if (R[x] < R[y])
		swap(x, y);
	P[y] = x;
	if (R[x] == R[y])
		++R[x];
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	link(x, y);
}

int main() 
{
	int T, N, M, u, v;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		if (t)
			cout << '\n';

		cin >> N;
		groups = N;

		for (int i = 1; i <= N; ++i) {
			P[i] = i;
			R[i] = 0;
		}

		for (int i = 1; i <= N; ++i) {
			cin >> V[i].x >> V[i].y;
		}

		cin >> M;
		for (int i = 1; i <= M; ++i) {
			cin >> u >> v;
			if (find(u) != find(v)) {
				--groups;
				merge(u, v);
			}
		}

		if (groups == 1) {
			puts("No new highways need");
			continue;
		}

		int e = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = i+1; j <= N; ++j) {
				if (find(i) == find(j)) continue;
				Vertex &v1 = V[i];
				Vertex &v2 = V[j];
				E[e++] = Edge((v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y), i, j);
			}
		}
		sort(E.begin(), E.begin()+e, cmp);

		e = 0;
		while (groups != 1) {
			Edge edge = E[e++];
			if (find(edge.u) != find(edge.v)) {
				--groups;
				merge(edge.u, edge.v);
				cout << edge.u << ' ' << edge.v << '\n';
				debug(e, groups);
			}
		}
	}
}
