#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
int grape[10005];
int drink[10005][3];
int ans = 0;

int main(void)
{
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &grape[i]);
	}
	drink[1][1] = grape[1];
	drink[2][0] = grape[1];
	drink[2][1] = grape[2];
	drink[2][2] = grape[1] + grape[2];

	for(int i = 3; i <= n; i++) {
		drink[i][0] = max(drink[i - 1][0], max(drink[i - 1][1], drink[i - 1][2]));
		drink[i][1] = drink[i - 1][0] + grape[i];
		drink[i][2] = drink[i - 1][1] + grape[i];
	}
	
	ans = max(drink[n][0], max(drink[n][1], drink[n][2]));

	printf("%d", ans);
	return 0;
}
