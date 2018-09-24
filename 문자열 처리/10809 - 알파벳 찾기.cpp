#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

//알파벳 26개
int ap[150];

int main()
{
	char word[105];
	scanf("%s", word);

	memset(ap, -1, sizeof(ap));

	for(int i = 0; word[i] != '\0'; i++) {
		if(ap[word[i] - 96] == -1) {
			ap[word[i] - 96] = i;
		}
	}

	for(int i = 1; i <= 26; i++) {
		printf("%d ", ap[i]);
	}
    return 0;
}
