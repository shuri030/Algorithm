#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int remain[43];

int main(void)
{
	int num, cnt = 0;

	for(int i = 0; i < 10; i++) {
		scanf("%d", &num);
		if(remain[num % 42] == 0) {
			remain[num % 42] = 1;
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}
