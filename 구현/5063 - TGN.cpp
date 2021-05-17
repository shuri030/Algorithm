#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int N;
	int r, e, c;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &r, &e, &c);

		if (e - c > r) {
			printf("advertise\n");
		}
		else if (e - c < r) {
			printf("do not advertise\n");
		}
		else {
			printf("does not matter\n");
		}
	}

	return 0;
}
