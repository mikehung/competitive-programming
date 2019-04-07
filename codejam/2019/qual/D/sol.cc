#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1024, MAX_F = 5, NUM_BLOCKS = 16;
typedef vector<string> BitsType;
int N, B, F;

void get_bits(BitsType &bits)
{
    for (int i = 0; i < MAX_N; ++i) {
        for (int f = 0; f < MAX_F-1; ++f) {
            if (((i%16) >> f) & 1) bits[f] += '1';
            else bits[f] += '0';
        }
    }

    for (int i = 0; i < MAX_N / NUM_BLOCKS; ++i) {
        if (i & 1) bits[MAX_F-1] += string(NUM_BLOCKS, '1');
        else bits[MAX_F-1] += string(NUM_BLOCKS, '0');
    }
}

void judge_bits(const BitsType &bits, BitsType &res)
{
    for (int i = 0; i < MAX_F; ++i) {
        cout << bits[i].substr(0, N) << endl;
        cin >> res[i];
    }
}

void answer(const BitsType &res)
{
    vector<bool> ok(N);
    auto parts = res[MAX_F-1];
    for (int i = 0, blks = 0; i < N-B; ++blks) {
        int start = i;
        while (i < N-B && parts[i] == parts[start]) {
            int v = 0;
            for (int f = 0; f < MAX_F-1; ++f) {
                if (res[f][i] == '1') v += (1 << f);
            }
            ok[blks*NUM_BLOCKS + v] = 1;
            ++i;
        }
    }
    for (int i = 0; i < N; ++i) if (!ok[i]) {
        cout << i << ' ';
    }
    cout << endl;
}

void verdict()
{
    int v;
    cin >> v;
    if (v == -1) exit(0);
}

void solve(int testcase)
{
    cin >> N >> B >> F;
    BitsType bits(MAX_F), res(MAX_F);
    get_bits(bits);
    judge_bits(bits, res);
    answer(res);
    verdict();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}
