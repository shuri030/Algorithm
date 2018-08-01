#include <stdio.h>
#include <iostream>
using namespace std;

int split[90010];

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 1; i <= 300; i++) {
		for(int j = 1; j <= 300; j++) {
			split[i * j] = (i * j) - 1;
		}
	}

	printf("%d", split[n * m]);

	return 0;
}