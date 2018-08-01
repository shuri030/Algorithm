#include <iostream>
#include <stdio.h> 
using namespace std;

int n, m, k, i, j, x, y;
int board[305][305];

int main(void)
{
	scanf("%d %d", &n, &m);
	
	for(int a = 1; a <= n; a++) {
		for(int b = 1; b <= m; b++) {
			scanf("%d", &board[a][b]);
		}
	}

	scanf("%d", &k);

	for(int tc = 1; tc <= k; tc++) {
		int sum = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		
		for(int a = i; a <= x; a++) {
			for(int b = j; b <= y; b++) {
				sum = sum + board[a][b];
			}
		}

		printf("%d\n", sum);

	}
	
	return 0;
}
