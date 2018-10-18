#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
	#define dbg(...)
#endif

const int N_MAX = 10000 + 5;
int n, m, hits[N_MAX], x[N_MAX], r[N_MAX], id[N_MAX], cnt, a, b;

void shoot(int i, int j, long long a, long long b)
{
	if (j < 0 || j >= n) return;
	j = id[j];
	if (hits[j] != -1) return;

	if ((a-x[j])*(a-x[j]) + b*b <= r[j]*r[j]) {
		hits[j] = i;
		++cnt;
	}
}

bool cmp(int i, int j)
{
	return x[i] < x[j];
}

bool cmp2(int i, int v)
{
	return x[i] < v;
}

int main()
{
	memset(hits, -1, sizeof(hits));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &x[i], &r[i]);
		id[i] = i;
	}
	sort(id, id+n, cmp);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &a, &b);
		int j = lower_bound(id, id+n, a, cmp2) - id;
		shoot(i, j-1, a, b);
		shoot(i, j, a, b);
		shoot(i, j+1, a, b);
	}
	cout << cnt << '\n';
	for (int i = 0; i < n; ++i) {
		cout << hits[i] << ' ';
	}
	cout << '\n';

	return 0;
}
