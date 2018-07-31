#include <iostream>
#include <algorithm>
using namespace std;

int cost[1010][3];
int dp[1010][3];

int main()
{
//첫 코드
	int r, g, b, n; //0 = r, 1 = g, 2 = b;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		cost[i][0] = r;
		cost[i][1] = g;
		cost[i][2] = b;
	}
	
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];
	
	for(int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	
	int ans = min(dp[n][0], dp[n][1]);
	ans = min(ans, dp[n][2]);

	printf("%d", ans);
}
