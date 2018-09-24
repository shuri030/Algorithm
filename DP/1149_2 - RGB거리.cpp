#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;
int n;
int board[1005][4];
int dp[1005][4];

int cal(int h, int c)
{
    if(h > n) {
        return 0;
    }
    
    int &ret = dp[h][c];
    
    if(ret != -1) {
        return ret;
    }
    
    ret = INT_MAX / 2;
    
    if(c == 1) {
        ret = min(ret, cal(h + 1, 2) + board[h][1]);
        ret = min(ret, cal(h + 1, 3) + board[h][1]);
    }
    else if(c == 2) {
        ret = min(ret, cal(h + 1, 1) + board[h][2]);
        ret = min(ret, cal(h + 1, 3) + board[h][2]);

    }
    else if(c == 3) {
        ret = min(ret, cal(h + 1, 1) + board[h][3]);
        ret = min(ret, cal(h + 1, 2) + board[h][3]);

    }
    
    dp[h][c] = ret;
    
    return ret;
    
}


int main()
{
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            scanf("%d", &board[i][j]);
            dp[i][j] = -1;
        }
    }
    printf("%d", min(min(cal(1, 1), cal(1, 2)), cal(1, 3)));
    
    
    
    return 0;
}