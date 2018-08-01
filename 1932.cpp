#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[505][505];
int tri[505][505];

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            scanf("%d", &tri[i][j]);
        }
    }
    
    //마지막 줄 초기화
    for(int i = 1; i <= n; i++) {
        dp[n][i] = tri[n][i];
    }
   
    for(int i = n - 1; i > 0; i--) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + tri[i][j];
        }
    }
    
    printf("%d", dp[1][1]);
    
}