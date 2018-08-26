#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N, S;
int num[25];
int cnt = 0;


void cal(int n, int sum)
{
	if(n > N) {
		return;
	}
	
	//포함
	sum = sum + num[n];
	if(sum == S) {
		cnt++;
	}
	cal(n + 1, sum);

	sum = sum - num[n];
	cal(n + 1, sum);

	return;
}

int main(void)
{
	scanf("%d %d", &N, &S);

	for(int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}

	cal(1, 0);
	
	printf("%d", cnt);
	return 0;
}
