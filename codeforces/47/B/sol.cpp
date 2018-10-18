#include <bits/stdc++.h>
using namespace std;

bool check(string &ans, vector<string> &A) {
	for (string &rule : A) {
		if (rule[1] == '>') {
			if (ans.find(rule[0]) < ans.find(rule[2]))
				return false;
		} else {
			if (ans.find(rule[0]) > ans.find(rule[2]))
				return false;
		}
	}	
	return true;
}

int main() {
	vector<string> A(3);
	for (int i = 0; i < 3; ++i)
		cin >> A[i];
	vector<string> answers = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
	for (auto &ans : answers) {
		if (check(ans, A)) {
			cout << ans << '\n';
			return 0;
		}
	}
	cout << "Impossible\n";
	return 0;    
}
