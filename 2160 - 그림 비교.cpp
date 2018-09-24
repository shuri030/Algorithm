#include <stdio.h>
#include <iostream>
#include <functional>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

int ans = INT_MAX;
char board[250][7];
int ma, mb;

void cmp(int a, int b)
{

	int cnt = 0, c = 1;
	int aa, bb;
	aa = a * 5;
	bb = b * 5;
	

	while(c < 6) {
		for(int j = 0; j < 7; j++) {
			if(board[aa][j] != board[bb][j]) {
				cnt++;
			}
		}
		c++; aa++; bb++;
	}
	if(ans > cnt) {
		ans = min(ans, cnt);
		ma = a; mb = b;
	}
	
}
int main()
{
	int N;
	scanf("%d", &N);

	for(int i = 0; i < (N * 5); i++) {
		for(int j = 0; j < 7; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}


	for(int i = 0; i < N - 1; i++) {
		for(int j = (i + 1); j < N; j++) {
			cmp(i, j);
		}
	}

	printf("%d %d\n", ma + 1, mb + 1);
	return 0;
}