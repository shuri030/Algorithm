#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	int sum = 0;
	
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		if(i < 10) { sum += 1;	}
		else if(i < 100) {	sum += 2;	}
		else if(i < 1000) {	sum += 3;	}
		else if(i < 10000) {	sum += 4;	}
		else if(i < 100000) {	sum += 5;	}
		else if(i < 1000000) {	sum += 6;	}
		else if(i < 10000000) {	sum += 7;	}
		else if(i < 100000000) {	sum += 8;	}
		else if(i < 1000000000) {	sum += 9;	}
	}

	printf("%d", sum);
  
   return 0;
}