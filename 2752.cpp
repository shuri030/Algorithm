#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int num[3];

int main(void)
{
	for(int i = 0; i < 3; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + 3);

	for(int i = 0; i < 3; i++) {
		printf("%d ", num[i]);
	}
	return 0;
}
