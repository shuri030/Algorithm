#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int M, a, b, ball = 1;
	scanf("%d", &M);

	for(int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);

		if(a == ball) {
			ball = b;
		}
		else if(b == ball) {
			ball = a;
		}
	}

	printf("%d", ball);
	return 0;
}