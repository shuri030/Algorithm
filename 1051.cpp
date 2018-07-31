#include <stdio.h>
#include <iostream>

using namespace std;

int N, M;
int board[55][55];

int main(void)
{
	int m = 1, k;
	scanf("%d %d", &N, &M);
	k = min(N, M);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	for(int i = 1; i <= N - 1; i++) {
		for(int j = 1; j <= M - 1; j++) {
			for(int x = 1; x <= k; x++) {
				if(((i + x) <= N) && ((j + x) <= M)) {
					if((board[i][j] == board[i + x][j]) && (board[i + x][j] == board[i][j + x]) && (board[i][j + x] == board[i + x][j + x])) {
						m = max(m, (x + 1)*(x + 1));
					}
				}
			}
		}
	}

	printf("%d\n", m);

	return 0;
}
