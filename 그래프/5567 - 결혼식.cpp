#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> rel[502];
int check[502];

int main()
{
	int n, m, a, b;

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		rel[a].push_back(b);
		rel[b].push_back(a);
	}

	check[1] = 1;
	int ans = 0;
	queue<int> q;

	for (int i = 0; i < rel[1].size(); i++) {
		q.push(rel[1][i]);
		check[rel[1][i]] = 1;
		ans++;
	}

	while (!q.empty()) {
		int f = q.front(); q.pop();
		for (int k = 0; k < rel[f].size(); k++) {
			if (check[rel[f][k]] == 0) {
				check[rel[f][k]] = 1;
				ans++;
			}
		}
	}

	printf("%d", ans);
	return 0;
}
