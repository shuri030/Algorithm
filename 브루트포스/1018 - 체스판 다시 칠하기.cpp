#include <stdio.h>
#include <iostream>
using namespace std;

char board[55][55];
int n, m;

int count(int x, int y) 
{
	int cnt = 0;

	if(board[x][y] ==  'B') {
		for(int i = x; i < x + 8; i++) {
			for(int j = y; j < y + 8; j++) {
				if((((i - x) % 2) == 0) && (((j - y) % 2) == 0)) {
					if(board[i][j] != 'B') {
						cnt++;
					}
				}
				else if((((i - x) % 2) != 0) && (((j - y) % 2) != 0)) {
					if(board[i][j] != 'B') {
						cnt++;
					}
				}
				else {
					if(board[i][j] != 'W') {
						cnt++;
					}
				}
			}
		}
	}

	else if(board[x][y] ==  'W') {
		for(int i = x; i < x + 8; i++) {
			for(int j = y; j < y + 8; j++) {
				if((((i - x) % 2) == 0) && (((j - y) % 2) == 0)) {
					if(board[i][j] != 'W') {
						cnt++;
					}
				}
				else if((((i - x) % 2) != 0) && (((j - y) % 2) != 0)) {
					if(board[i][j] != 'W') {
						cnt++;
					}
				}
				else {
					if(board[i][j] != 'B') {
						cnt++;
					}
				}
			}
		}
	}

	return cnt;

}

int main(void)
{
	//input
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		char temp[55];
		scanf("%s", temp);
		for(int j = 0; j < m; j++) {
			board[i][j] = temp[j];
		}
	}

	int ans = 100000;

	for(int i = 0; i < (n - 8) + 1; i++) {
		for(int j = 0; j < (m - 8) + 1; j++) {
			if(board[i][j] == 'B') {
				ans = min(ans, count(i, j));
				board[i][j] = 'W';
				ans = min(ans, (count(i, j) + 1));
				board[i][j] = 'B';
			}
			else {
				ans = min(ans, count(i, j));
				board[i][j] = 'B';
				ans = min(ans, (count(i, j) + 1)) ;
				board[i][j] = 'W';
			}
		}
	}

	printf("%d", ans);

	return 0;
}