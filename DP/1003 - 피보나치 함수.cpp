#include <stdio.h>
#include <iostream>
using namespace std;

int fibo0[45];
int fibo1[45];

int main(void)
{
	int t, n;

	scanf("%d", &t);

	fibo0[0] = 1;
	fibo1[0] = 0;
	fibo0[1] = 0;
	fibo1[1] = 1;

	for(int i = 2; i <= 40; i++) {
		fibo0[i] = fibo0[i - 2] + fibo0[i - 1];
		fibo1[i] = fibo1[i - 2] + fibo1[i - 1];
	}
	for(int i = 1; i <= t; i++) {
		scanf("%d", &n);
		printf("%d %d\n", fibo0[n], fibo1[n]);
	}

	return 0;
}