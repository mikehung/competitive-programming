/*
ID: mike51
TASK: milk2
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int s, e;
    Interval(int start, int end): s(start), e(end) {}
};

bool cmp(const Interval &i1, const Interval &i2)
{
    return i1.s < i2.s;
}

int n, s, e, yes, no;
vector<Interval> intervals;

int main() {
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> s >> e;
        intervals.emplace_back(s, e);
    }
    sort(intervals.begin(), intervals.end(), cmp);
    s = e = 0;
    for (Interval &interval: intervals) {
        if (interval.s > e) {
            s = interval.s;
            if (e) no = max(no, interval.s - e);
        }
        e = max(e, interval.e);
        yes = max(yes, e - s);
    }
    fout << yes << ' ' << no << '\n';
    return 0;
}
