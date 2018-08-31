#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include<string.h>
using namespace std;

int vertex[105][105];
int answer[105][105];
vector<int> adj[105];
int visit[105];

void BFS(int i) {

	visit[i] = 1;
	queue<int> q;
	q.push(i);

	while(!q.empty()) {
		int cur = q.front(); //i
		q.pop();

		for(int k = 0; k < adj[cur].size(); k++) {
			answer[i][adj[cur][k]] = 1;
			if(visit[adj[cur][k]] == 0) {
				q.push(adj[cur][k]);
				visit[adj[cur][k]] = 1;
			}

		}

	}

}
int main()
{
	int N;
	int start;

	cin >> N;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &vertex[i][j]);

			if(vertex[i][j] == 1) {
				adj[i].push_back(j);

			}

		}
	}

	for(int i = 0; i < N; i++) {
		memset(visit, 0 ,sizeof(visit));
		BFS(i);
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}

}
