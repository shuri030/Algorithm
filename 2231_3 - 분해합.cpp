#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int sum[1000010];

int de_plus(int n) 
{
	int p = 1000000;
	int r = 0;

	
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
	int tmp, flag = 0;
	scanf("%d", &N);
	
	for(int i = 1; i <= 1000000; i++) {
		tmp = i + de_plus(i);
		if(sum[i] == 0) 
			sum[i] = tmp;
	}

	for(int i = 1; i <= 1000000; i++) {
		if(sum[i] == N) {
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