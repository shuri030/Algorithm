#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	queue<int> card;

	int N;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		card.push(i);
	}

	int n;

	while(1) {
		n = card.front(); 
		card.pop();
	
		if(N == 1) {
			printf("%d", n); 
			break; 
		}

		n = card.front();
		card.pop();
		card.push(n);	
		N--;
	}

	return 0;
}