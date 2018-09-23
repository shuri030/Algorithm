#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;

int sel[100002];
int visit[100002];
int team[100002];
queue<int> q;

void go(int top, int cur)
{
	if (visit[cur] == 1 && cur == top) {
		while (!q.empty()) {
			int n = q.front();
			q.pop();
			team[n] = 1;
		}
	}

	else if (visit[cur] == 1 && cur != top) {
		while (!q.empty()) {
			int n = q.front();
			q.pop();
			if (n != top) {
				visit[n] = 0;
			}
		}
		return;
	}

	else {
		visit[cur] = 1;
		q.push(cur);
		go(top, sel[cur]);
	}

}

int main()
{
	int t;
	scanf("%d", &t);

	for (int tc = 0; tc < t; tc++) {
		int n;
		int cnt = 0;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &sel[i]);
		}

		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
				go(q.front(), sel[i]);

				while (!q.empty()) { q.pop(); }
			}
		}

		for (int i = 1; i <= n; i++) {
			if (team[i] == 0) {
				cnt++;
			}
		}

		printf("%d\n", cnt);

		memset(team, 0, sizeof(team));
		memset(visit, 0, sizeof(visit));
		memset(sel, 0, sizeof(sel));

	}

	return 0;
}
