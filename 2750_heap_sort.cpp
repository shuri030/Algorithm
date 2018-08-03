// < 힙 정렬 heap sort >
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int num[1001];

int main()
{	
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	//최대 힙 생성하기
	for(int i = 1; i < N; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if(num[root] < num[c]) {
				int tmp = num[root];
				num[root] = num[c];
				num[c] = tmp;
			}
			c = root;
		} while(c != 0); 
	}

	//크기를 줄여가며 반복적으로 힙 구성
	for(int i = N - 1; i >= 0; i--) {
		int tmp = num[i];
		num[i] = num[0];
		num[0] = tmp;

		int root = 0;
		int c = 1;
		do {
			c = root * 2 + 1;
			//자식중에 큰 값
			if(num[c] < num[c + 1] && c < i - 1) {
				c++;
			}
			//루트보다 자식이 크면 교환
			if(num[root] < num[c] && c < i) {
				int tmp = num[root];
				num[root] = num[c];
				num[c] = tmp;
			}
			root = c;
		} while(c < i);
	}

	for(int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
	
    return 0;
}