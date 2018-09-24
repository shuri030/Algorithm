#include <iostream>
#include <string.h>
using namespace std;

int n, num, max_n = 0, cnt = 0;
int board[105][105];
int visit[105][105];
int check[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int i, int j) {
	
	visit[i][j] = 1;

	for(int k = 0; k < 4; k++) {
		if(i + dx[k] >= 0 && j + dy[k] >= 0 && i + dx[k] < n && j + dy[k] < n) {
			if(visit[i + dx[k]][j + dy[k]] == 0 && check[i + dx[k]][j + dy[k]] == 0) {
				DFS(i + dx[k], j + dy[k]);
			}
		}
	}

}
void is_sinked(int m) {


	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] <= m ) {
					check[i][j] = 1; //잠기면 1
			}
		}
	}

	
}


int main()
{
	int ans = 1;

	cin >> n;

	//지역 입력
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &num);
			board[i][j] = num;
			if(num > max_n)
				max_n = num;
		}
	}
	
	for(int i = 0; i <= max_n; i++) {
		is_sinked(i); //물에 잠기는지

		for(int j = 0; j < n; j++) {
			for(int d = 0; d < n; d++) {
				if(visit[j][d] == 0 && check[j][d] == 0) {
					DFS(j, d);
					cnt++;
				}
			}
		}

		if(ans < cnt)
			ans = cnt;
		memset(check, 0, sizeof(check));
		memset(visit, 0, sizeof(visit));

		cnt = 0;
	}

	printf("%d", ans);
}
