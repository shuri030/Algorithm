#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <functional>
using namespace std;

vector<pair<int, int> > v[1002];
int N, M;
int s, e;

int dijkstra(int s)
{
	vector<int> ans(N + 1, INT_MAX / 2);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
	ans[s] = 0;
	pq.push(make_pair(s, 0));

	while(!pq.empty()) {
		int here = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if(cost > ans[here]) {
			continue;
		}

		for(int i = 0; i < v[here].size(); i++) {
			int there = v[here][i].first;
			int next_cost = cost + v[here][i].second;

			if(next_cost < ans[there]) {
				ans[there] = next_cost;
				pq.push(make_pair(there, next_cost));
			}
		}
	}

	return ans[e];
}

int main()
{
	int a, b, c;

	scanf("%d", &N);
	scanf("%d", &M);

	for(int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}

	scanf("%d %d", &s, &e);

	printf("%d\n", dijkstra(s));

	return 0;
}
