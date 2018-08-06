#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int a[21];

int main()
{	
	int N, K;
	scanf("%d %d", &N, &K);

	for(int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		getchar(); // ',' 입력받기
	}
	
	while(K > 0) {
		for(int i = 0; i < N - 1; i++) {
			a[i] = a[i + 1] - a[i];
		}
		K--; N--;
	}
	
	for(int i = 0; i < N; i++) {
		printf("%d", a[i]);
		if(i != N - 1) { printf(","); }
	}
    return 0;
}