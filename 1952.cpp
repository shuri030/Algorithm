#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int M, N;
int board[103][103];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int draw(int x, int y)
{
	int n = 1, d = 0, xx, yy;
	int cnt = 0, m_cnt = 1;
	board[x][y] = n;


	while(m_cnt < M * N) {
		xx = x + dx[d]; 
		yy = y + dy[d];
		if((xx < 1) || (yy < 1) || (xx > M) || (yy > N) || (board[xx][yy] != 0)) {
			d++;
			if(d == 4) { d = 0; }
			cnt++;
			x = x + dx[d]; 
			y = y + dy[d]; //제자리로
		}
		else {
			x = x + dx[d]; 
			y = y + dy[d]; //그 방향으로
		}
		m_cnt++;
		board[x][y] = 1;
	}

	return cnt;
}

int main()
{	
	
	scanf("%d %d", &M, &N);

	printf("%d\n", draw(1, 1));


    return 0;
}