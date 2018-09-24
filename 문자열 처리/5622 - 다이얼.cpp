#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


int main()
{
	char word[20];
	int sum = 0;

	scanf("%s", word);

	for(int i = 0; i < strlen(word); i++) {
		if(word[i] >= 'A' && word[i] <= 'C') {
			sum += 3;
		}
		else if(word[i] >= 'D' && word[i] <= 'F') {
			sum += 4;
		}
		else if(word[i] >= 'G' && word[i] <= 'I') {
			sum += 5;
		}
		else if(word[i] >= 'J' && word[i] <= 'L') {
			sum += 6;
		}
		else if(word[i] >= 'M' && word[i] <= 'O') {
			sum += 7;
		}
		else if(word[i] >= 'P' && word[i] <= 'S') {
			sum += 8;
		}
		else if(word[i] >= 'T' && word[i] <= 'V') {
			sum += 9;
		}
		else if(word[i] >= 'W' && word[i] <= 'Z') {
			sum += 10;
		}
	}

	printf("%d", sum);

    return 0;
}
