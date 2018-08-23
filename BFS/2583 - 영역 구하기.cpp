#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int board[105][105];
int visit[105][105];
int xx[4] = {1, 0, -1, 0};
int yy[4] = {0, 1, 0, -1};
vector<int> ans;
queue<pair<int, int>> q;
int N, M, K;

int BFS(int i, int j) {

	int cnt = 1;
	visit[i][j] = 1;
	q.push(make_pair(i, j));

	while(!q.empty()) {
		int bx = q.front().first;
		int by = q.front().second;
		q.pop();

		for(int k = 0; k < 4; k++) {
			if(bx + xx[k] >= 0 && by + yy[k] >= 0 && bx + xx[k] < M && by + yy[k] < N) {
				if(visit[bx + xx[k]][by + yy[k]] == 0 && board[bx + xx[k]][by + yy[k]] == 0) {
					cnt++;
					q.push(make_pair(bx + xx[k], by + yy[k]));
					visit[bx + xx[k]][by + yy[k]] = 1;
				}
			}
		}
	}

	return cnt;
}
int main()
{

	int l_x, l_y, r_x, r_y;
	int first_cnt = 0;

	scanf("%d %d %d", &M, &N, &K);
	//입력
	for(int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &l_x, &l_y, &r_x, &r_y);

		for(int j = l_x; j < r_x; j++) {
			for(int k = l_y; k < r_y; k++) {
				board[k][j] = 1;
			}
		}
	}


	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			if(board[i][j] == 0 && visit[i][j] == 0) {
				ans.push_back(BFS(i, j));
				first_cnt++; //빈칸영역 갯수
			}
		}
	}



	/*for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		cout << endl;
	}*/

	sort(ans.begin(), ans.end()); //오름차순 정렬

	printf("%d\n", first_cnt);
	for(int f = 0; f < first_cnt; f++) {
		printf("%d ", ans[f]);
	}
}
