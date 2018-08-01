#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

long long int num[95];

int main()
{
	int n;

	scanf("%d", &n);

	num[1] = 1;
	num[2] = 1;
	for(int i = 3; i <= 90; i++) {
		num[i] = num[i - 2] + num[i - 1];
	}

	printf("%lld", num[n]);
	
	return 0;
}
