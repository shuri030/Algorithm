#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int num[100003];
int dp[100003];
int ans;

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    ans = dp[0] = num[0];
    
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + num[i], num[i]);
        if(ans < dp[i]) { ans = dp[i]; }
    }
    
    printf("%d", ans);
    return 0;
}