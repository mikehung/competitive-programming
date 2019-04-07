#include <bits/stdc++.h>

using namespace std;

const int NUM = 26;
int T = 10000, N = 10000;
vector<bool> table(N, true);
vector<int> primes;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void sieve()
{
    for (int i = 2; i < N; ++i) if (table[i]) {
        primes.push_back(i);
        for (int j = i * i; j < N; j += i) {
            table[j] = false;
        }
    }
}

map<char, int> get_primes()
{
    shuffle(primes.begin(), primes.end(), rng);
    sort(primes.begin(), primes.begin() + NUM);
    map<char, int> mp;
    for (int i = 0; i < NUM; ++i) {
        mp[(char) ('A' + i)] = primes[i];
    }
    return mp;
}

vector<int> get_testcase(const string s, map<char, int> mp)
{
    vector<int> res;
    int sz = s.size();
    for (int i = 0; i < sz-1; ++i) {
        res.push_back(mp[s[i]] * mp[s[i+1]]);
    }
    return res;
}

string get_s(int L)
{
    string s;
    for (int i = 0; i < L; ++i) {
        if (i < NUM) s.push_back((char) 'A'+i);
        else s.push_back((char) 'A'+(rng() % NUM));
    }
    shuffle(s.begin(), s.end(), rng);
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    vector<vector<int>> in;
    vector<string> out;
    for (int i = 0; i < T; ++i) {
        int L = rng() % 76 + 26;
        string s = get_s(L);
        in.push_back(get_testcase(s, get_primes()));
        out.push_back(s);
    }
    ofstream o1("../in2");
    ofstream o2("../out2");
    o1 << T << endl;
    for (int i = 0; i < T; ++i) {
        o1 << N << ' ' << out[i].size() - 1 << endl;
        for (auto v: in[i]) o1 << v << ' '; o1 << endl;
    }
    for (int i = 0; i < T; ++i) {
        o2 << "Case #" << i+1 << ": " << out[i] << endl;
    }

    return 0;
}
