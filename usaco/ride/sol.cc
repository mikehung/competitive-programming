/*
ID: mike51
TASK: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string s1, s2;
    int p1 = 1, p2 = 1;
    fin >> s1 >> s2;
    for (auto &ch : s1)
        p1 *= ch-'A'+1;
    for (auto &ch : s2)
        p2 *= ch-'A'+1;
    if ((p1 % 47) == (p2 % 47))
        fout << "GO\n";
    else
        fout << "STAY\n";

    return 0;
}
