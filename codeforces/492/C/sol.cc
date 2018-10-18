#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
	#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
	#define dbg(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

struct Exam {
    ll point, essay;
};

bool byEssay(const Exam& e1, const Exam &e2)
{
    return e1.essay < e2.essay;
}

int main()
{
    vector<Exam> exams;
    ll n, r, avg;
    Exam exam;
	scanf("%lld %lld %lld", &n, &r, &avg);
    ll tot_points = n * avg, tot_essays = 0, offer;
    for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", &exam.point, &exam.essay);
        tot_points -= exam.point;
        if (exam.point < r) {
            exams.push_back(exam);
        }
    }
    sort(exams.begin(), exams.end(), byEssay);
    int i = 0;
    while (tot_points > 0) {
        exam = exams[i++];
        offer = min(tot_points, r-exam.point);
        tot_points -= offer;
        tot_essays += offer * exam.essay;
    }
	printf("%lld\n", tot_essays);

	return 0;
}
// Time: O(nlogn), Space: O(n)
