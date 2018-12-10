#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool board[102][102];

int main()
{
	int p, a, b;
	int cnt = 0;
	scanf("%d", &p);

	for (int k = 0; k < p; k++) {
		scanf("%d %d", &a, &b);

		for (int i = a; i <= a + 9; i++) {
			for (int j = b; j <= b + 9; j++) {
				if (!board[i][j]) {
					board[i][j] = true;
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
