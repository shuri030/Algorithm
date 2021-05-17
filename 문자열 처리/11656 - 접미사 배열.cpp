#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

string input;
vector<string> ans;

int main()
{
	cin >> input;

	string tmp = "";

	for (int i = 0; i < input.size(); i++) {
		tmp = input.substr(i);
		ans.push_back(tmp);
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
