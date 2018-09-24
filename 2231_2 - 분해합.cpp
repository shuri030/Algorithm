#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int de_plus(int n) 
{
	int p = 1000000;
	int r = n;

	
	while(p > 0) {
		if((n / p) > 0) {
			r += (n / p);
			n = (n % p);
		}
		p = p / 10;
	}
	
	return r;

}

int main()
{
	int N;
	int tmp, flag = 0;
	scanf("%d", &N);
	
	for(int i = 1; i <= 1000000; i++) {
		int sum = de_plus(i);
		if(sum == N) {
			flag = 1;
			printf("%d", i);
			break;
		}
	}
	
	if(flag == 0) {
		printf("0");
	}
  
   return 0;
}