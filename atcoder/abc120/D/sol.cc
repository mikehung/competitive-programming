#include <bits/stdc++.h>

using namespace std;

const int NMAX = (int) 1e5+11;
int par[NMAX], rnk[NMAX], grp[NMAX];

void init()
{
    for (int i = 0; i < NMAX; ++i) {
        par[i] = i;
        grp[i] = 1;
    }
}

int find(int x) {
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        grp[x] += grp[y];
        if (rnk[x] == rnk[y]) ++rnk[x];
        return 1;
    }
    return 0;
}

int group(int x) {
    return grp[find(x)];
}

void solve(long long N, long long M, vector<long long> A, vector<long long> B)
{
    init();
    long long cnt = 1ll * N * (N-1) / 2;
    vector<long long> ans(M);
    for (int i = M-1; i >= 0; --i) {
        ans[i] = cnt;
        long long cc = 1ll * group(A[i]) * group(B[i]);
        if (merge(A[i], B[i])) {
            cnt -= cc;
        }
    }
    for (auto &x: ans) {
        cout << x << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;
    long long M;
    cin >> M;
    vector<long long> A(M);
    vector<long long> B(M);
    for(int i = 0 ; i < M ; i++){
        cin >> A[i];
        cin >> B[i];
    }
    solve(N, M, move(A), move(B));
    return 0;
}
