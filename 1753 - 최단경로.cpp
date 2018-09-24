#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>

#define MAX_V 20005
using namespace std;

int V, e, k;
int u, v, w;

int ans[MAX_V];
vector<pair<int, int>> vec[MAX_V];

int main(void)
{
	scanf("%d %d", &V, &e);
	scanf("%d", &k);

	for(int i = 1; i <= e; i++) {
		scanf("%d %d %d", &u, &v, &w);

		vec[u].push_back(make_pair(v, w));
	}

	for(int i = 1; i <= V; i++) {
		ans[i] = INT_MAX / 2;
	}

	ans[k] = 0;
	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, k));
	

	while(!pq.empty()) {

		int cur = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(ans[here] < cur) {
			continue;
		}

		for(int i = 0; i < vec[here].size(); i++) {
			int next = vec[here][i].first;
			int nextDist = cur + vec[here][i].second;

			if(ans[next] > nextDist) {
				ans[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}

	}
	for(int i = 1; i <= V; i++) {
		if(k != i && ans[i] == (INT_MAX / 2)) {
			cout << "INF" << endl;
		}
		else {
			cout << ans[i] << endl;
		}
	}

	return 0;
}
