#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

set<string> d;
set<string> db;
int N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	string name;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> name;
		d.insert(name);
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		if (d.count(name) == true) { // set의 값이 존재하면 true, 아니면 false
			db.insert(name);
		}

	}

	cout << db.size() << "\n";
	for (auto iter = db.begin(); iter != db.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}
