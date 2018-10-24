#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

long long wtoll(string word)
{
    long long res = 0;
    for (char ch : word)
        res = res * 32 + (ch - 'a' + 1);
    return res;
}

int main()
{
    string line, word;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<long long> W;
        while (iss >> word) {
            W.push_back(wtoll(word));
        }
        int n = W.size();
        map<long long, long long> M;
        long long C = 1, wj, mod;
        bool ok = false;
        while (!ok) {
            for (auto w : W) if (C % w == 0) {
                ok = true;
                break;
            }
            if (!ok) {
                ++C;
                continue;
            }

            M.clear();
            for (auto wi : W) {
                mod = (C/wi) % n;
                if (M.count(mod)) {
                    wj = M[mod];
                    C = min((C/wi+1)*wi, (C/wj+1)*wj); 
                    break;
                } else {
                    M[mod] = wi;
                }
            }
            ok = M.size() == n;
        }
        printf("%s\n%lld\n\n", line.c_str(), C);
    }
}
// Time: O(), Space: O()
