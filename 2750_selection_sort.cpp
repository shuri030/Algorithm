// < 선택정렬 selection sort >
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int num[1002];

int main()
{	
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	//가장 작은 것 구해서 제일 앞으로 보내기
	int min_num = 1001, min_index, tmp;
	for(int i = 0; i < N; i++) {
		for(int j = i; j < N; j++) {
			if(min_num > num[j]) {
				min_num = num[j];
				min_index = j;
			}
		}
		tmp = num[i];
		num[i] = num[min_index];
		num[min_index] = tmp;
		min_num = 1001;
	}

	for(int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
	
    return 0;
}