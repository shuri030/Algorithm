#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char res[83];

int main(void)
{
	int tc, point, st;
	scanf("%d", &tc);

	for(int t = 1; t <= tc; t++) {
		point = 0; st = 1;
		memset(res, 0, sizeof(res));
		scanf("%s", res);

		for(int i = 0; i < strlen(res); i++) {
			if(res[i] == 'O') {
				point += st;
				st++;
			}
			else if(res[i] == 'X') {
				st = 1;
			}
		}
		printf("%d\n", point);
	}

	return 0;
}
