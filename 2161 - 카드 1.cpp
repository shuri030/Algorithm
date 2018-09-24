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

	while(N > 0) {
		n = card.front(); 
		card.pop();
		printf("%d ", n);
		N--;

		if(N == 1) { 
			printf("%d ", card.front()); 
			break; 
		}
		n = card.front();
		card.pop();
		card.push(n);
	}

	return 0;
}