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
#include <complex>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int NMAX = 28;

int main()
{
    vector<int> blocks[NMAX];
    int positions[NMAX];
    int n, blk, blk1, blk2, pos1, pos2;
    string act1, act2;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        blocks[i].push_back(i);
        positions[i] = i;
    }

    while (cin >> act1) {
        if (act1 == "quit") break;
        cin >> blk1 >> act2 >> blk2;
        pos1 = positions[blk1];
        pos2 = positions[blk2];
        if (pos1 == pos2) continue;
        if (act2 == "onto") {
            while (blocks[pos2].back() != blk2) {
                blk = blocks[pos2].back();
                blocks[pos2].pop_back();
                blocks[blk].push_back(blk);
                positions[blk] = blk;
            }
        }
        if (act1 == "move") {
            while (blocks[pos1].back() != blk1) {
                blk = blocks[pos1].back();
                blocks[pos1].pop_back();
                blocks[blk].push_back(blk);
                positions[blk] = blk;
            }
            blocks[pos1].pop_back();
            blocks[pos2].push_back(blk1);
            positions[blk1] = pos2;
        } else if (act1 == "pile") {
            vector<int> blks;
            while (blocks[pos1].back() != blk1) {
                blk = blocks[pos1].back();
                blocks[pos1].pop_back();
                blks.push_back(blk);
            }
            blocks[pos1].pop_back();
            blocks[pos2].push_back(blk1);
            positions[blk1] = pos2;
            reverse(blks.begin(), blks.end());
            for (int i = 0; i < blks.size(); ++i) {
                blk = blks[i];
                blocks[pos2].push_back(blk);
                positions[blk] = pos2;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << i << ':';
        for (auto x : blocks[i]) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
}
// Time: O(), Space: O()
