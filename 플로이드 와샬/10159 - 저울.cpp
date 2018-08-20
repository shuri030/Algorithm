#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <functional>

using namespace std;

int result[102][102];

int main()
{
	int N, M;
	int a, b;

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				result[i][j] = INT_MAX / 2;
			}
			else {
				result[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		result[a][b] = 1;
		result[b][a] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (result[i][k] == 1 && result[k][j] == 1)
					result[i][j] = 1;
				else if (result[i][k] == 0 && result[k][j] == 0)
					result[i][j] = 0;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (result[i][j] == INT_MAX / 2 && result[j][i] == INT_MAX / 2) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}

	return 0;
}
