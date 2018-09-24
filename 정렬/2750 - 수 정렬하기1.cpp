#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int num[1001];

int main()
{
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	sort(num, num + N);

	for(int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}

	return 0;
}