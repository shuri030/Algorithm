#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int board[22][22];
bool check[22][22];

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < n; j++) {
				if (i == j || j == k || i == k) continue;
				if (board[i][j] == board[i][k] + board[k][j]) {
					check[i][j] = true;
				}
				else if (board[i][j] > board[i][k] + board[k][j]) {
					printf("%d", -1);
					return 0;
				}
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (!check[i][j]) {
				cnt += board[i][j];
			}
		}
	}

	printf("%d", cnt);
	return 0;
}
