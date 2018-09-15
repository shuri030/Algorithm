#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;
int N, M;
int num[7] = { 1000000, 100000, 10000, 1000, 100, 10, 1 };
int min_n, max_n;
int min_m, max_m;

int main()
{
	scanf("%d %d", &N, &M);

	//첫번째 수
	int i = 0, start;
	while (i < 7) {
		if (N / num[i] > 0) {
			start = i;
			break;
		}
		i++;
	}
	while (start < 7) {
		int n = N / num[start];
		if (n == 5) {
			min_n = min_n + (n * num[start]);
			max_n = max_n + (6 * num[start]);
		}
		else if (n == 6) {
			min_n = min_n + (5 * num[start]);
			max_n = max_n + (n * num[start]);
		}
		else {
			min_n = min_n + (n * num[start]);
			max_n = max_n + (n * num[start]);
		}
		N = N % num[start];
		start++;
	}

	//두번째 수
	i = 0, start = 0;
	while (i < 7) {
		if (M / num[i] > 0) {
			start = i;
			break;
		}
		i++;
	}
	while (start < 7) {
		int n = M / num[start];
		if (n == 5) {
			min_m = min_m + (n * num[start]);
			max_m = max_m + (6 * num[start]);
		}
		else if (n == 6) {
			min_m = min_m + (5 * num[start]);
			max_m = max_m + (n * num[start]);
		}
		else {
			min_m = min_m + (n * num[start]);
			max_m = max_m + (n * num[start]);
		}
		M = M % num[start];
		start++;
	}

	printf("%d %d\n", min_n + min_m, max_n + max_m);

	return 0;
}
