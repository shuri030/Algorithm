#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int de_plus(int n) 
{
	int r = n;

	while(n != 0) {
		r += (n % 10);
		n = (n / 10);
	}
	
	return r;

}

int main()
{
	int N;
	int tmp, flag = 0;

	scanf("%d", &N);
	
	for(int i = 1; i <= 1000000; i++) {
		if(de_plus(i) == N) {
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