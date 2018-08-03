#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int c[10];
int num[10] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

int main()
{	
	int N, st;
	scanf("%d", &N);
	
	for(int i = 0; i < 10; i++) {
		if(N / num[i] > 0) {
			st = i;
			break;
		}
	}

	for(int i = st; i < 10; i++) {
		c[N / num[i]]++;
		N = N % num[i];
	}

	for(int i = 9; i >= 0; i--) {
		if(c[i] != 0) {
			for(int j = 0; j < c[i]; j++) {
				printf("%d", i);
			}
		}
	}
	
    return 0;
}