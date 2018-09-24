#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;




int main(void)
{
	int on = 0, off = 0;
	int people = 0;
	int ans = 0;

	for(int i = 1; i <= 4; i++) {

		scanf("%d %d", &on, &off);
		people = people - on;

		if(people > ans) 
			ans = people;

		people = people + off;

		if(people > ans) 
			ans = people;

	}

	printf("%d\n", ans);

	return 0;
}
