#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;
int M, N;
int board[505][505];
int dp[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int move(int x, int y)
{
    int cnt = 0;
    
    if((x == M) && (y == N)) {
        return 1;
    }
    
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    
    for(int k = 0; k < 4; k++) {
        int xx = dx[k] + x;
        int yy = dy[k] + y;
        if((xx >= 1) && (yy >= 1) && (xx <= M) && (yy <= N)) {
            if(board[xx][yy] < board[x][y]) {
                cnt += move(xx, yy);
            }
        }
        
    }
    
    dp[x][y] = cnt;
    return cnt;
}

int main()
{
    
    scanf("%d %d", &M, &N);
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &board[i][j]);
            dp[i][j] = -1;
        }
    }
    
    printf("%d\n", move(1, 1));
    
    
    return 0;
}