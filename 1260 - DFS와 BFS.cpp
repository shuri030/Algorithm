#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm> 
#include <limits.h>

using namespace std;

int n, m, v;

int adj[1005][1005];
int visit[1005];


void BFS(int num) {

	visit[num] = 1;
	queue<int> q;
	q.push(num);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(int k = 1; k <= n; k++) {

			if(visit[k] == 0 && adj[cur][k] == 1) {
				printf("%d ", k);
				q.push(k);
				visit[k] = 1;
			}
		}

	}


}

void DFS(int num) {

	visit[num] = 1;

	for(int k = 1; k <= n; k++) {

			if(visit[k] == 0 && adj[num][k] == 1) {
				printf("%d ", k);
				DFS(k);
			}
		}
}


int main() 
{
	int a, b;

	scanf("%d %d %d", &n, &m, &v);

	for(int i = 1; i <= m; i++) {

		scanf("%d %d", &a, &b);

		adj[a][b] = 1;
		adj[b][a] = 1;

	}

	printf("%d ", v);
	DFS(v);

	printf("\n");
	memset(visit, 0, sizeof(visit));

	printf("%d ", v);
	BFS(v);
	

}
