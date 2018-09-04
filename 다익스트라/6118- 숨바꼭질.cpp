#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
typedef pair<int, int> P;
vector<P> v[20002];
int hide_num = 0, cnt = 0;
int max_dis = 0;

struct sorting {
	int operator() (P a, P b) {
		return a.second > b.second;
	}
};

void dijkstra(int k)
{
	priority_queue<P, vector<P>, sorting> pq;
	vector<int> ans(N + 2, INT_MAX / 2);

	ans[k] = 0;
	pq.push({ k, 0 });

	while (!pq.empty()) {

		int here = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (ans[here] < cost) { continue;  }

		for (int i = 0; i < v[here].size(); i++) {
			int there = v[here][i].first;
			int t_cost = cost + v[here][i].second;

			if (t_cost < ans[there]) {
				ans[there] = t_cost;
				max_dis = max(max_dis, t_cost);
				pq.push({ there, t_cost });
			}
		}
	}



	for (int i = 1; i <= N; i++) {
		if (i == k) { continue;  }
		if (ans[i] == max_dis) {
			if (hide_num == 0) {
				hide_num = i;
			}
			cnt++;
		}
	}


}



int main()
{
	 int a, b;
	 scanf("%d %d", &N, &M);

	 for (int i = 1; i <= M; i++) {
		 scanf("%d %d", &a, &b);
		 v[a].push_back({ b, 1 });
		 v[b].push_back({ a, 1 });
	 }

	 dijkstra(1);

	 printf("%d %d %d", hide_num, max_dis, cnt);

	return 0;
}
