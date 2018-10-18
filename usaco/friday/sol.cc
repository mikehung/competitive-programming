/*
ID: mike51
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int get_days(int year, int month)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month != 2)
        return 31;
    if (year % 4)
        return 28;
    if (!(year % 100) && year % 400)
        return 28;
    return 29;
}

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int cnt[10];
    int N, year = 1900, month = 1, day = 1, weekday = 1;
    fin >> N;
    memset(cnt, 0, sizeof(cnt));
    while (year != 1900+N) {
        if (day == 13) cnt[weekday]++;
        if (++weekday > 7) weekday = 1;
        if (++day > get_days(year, month))
            day = 1, ++month;
        if (month > 12)
            month = 1, ++year;
    }
    int idx[] = {6, 7, 1, 2, 3, 4, 5};
    for (int i = 0; i < 6; ++i)
        fout << cnt[idx[i]] << ' ';
    fout << cnt[5] << '\n';
    return 0;
}
