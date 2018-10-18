#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	char n[6];
	int ans = 0;
	scanf("%s", &n);

	int j = 0;
	for (int i = strlen(n) - 1; i >= 0; i--) {
		if (n[i] - '0' >= 0 && n[i] - '0' <= 9) {
			ans = ans + ((n[i] - '0') * pow(16, j));
		}
		else {
			int p = n[i] - 'A' + 10;
			ans = ans + (p * pow(16, j));
		}
		j++;
	}

	printf("%d", ans);

	return 0;

}
