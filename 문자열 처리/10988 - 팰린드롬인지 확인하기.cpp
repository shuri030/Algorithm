#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char word[110];
	int flag = 1;

	scanf("%s", word);

	for(int i = 0; i < strlen(word) / 2; i++) {
		if(word[i] != word[strlen(word) - i - 1]) {
			flag = 0;
		}
	}

	printf("%d", flag);

}
