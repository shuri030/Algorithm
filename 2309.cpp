#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

int height[10];
int visit[10];
int flag = 0;

void find_who(int n, int cur, int sum)
{
	if(flag == 1) {	return; }
	if(n >= 7) {
		if(sum == 100) {
			flag = 1;
			for(int i = 0; i < 9; i++) {
				if(visit[i] == 1) {
					printf("%d\n", height[i]);
				}
			}
		}
		return;
	}

	for(int i = cur; i < 9; i++) {
		//printf("n = %d cur = %d num = %d\n", n, cur, height[i]);
		visit[i] = 1;
		find_who(n + 1, i + 1, sum + height[i]);
		visit[i] = 0;
		if(flag == 1) {	return; }
	}
	return;
}

int main()
{
	
	for(int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}

	sort(height, height + 9);

	find_who(0, 0, 0);

	return 0;
}
