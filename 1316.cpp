#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int alpha[30];


int main() 
{
	int N;
	int cnt = 0;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		memset(alpha, 0, sizeof(alpha));
		char word[105];
		scanf("%s", word);

		int j = 0, flag = 0;
		while(j <= (strlen(word) - 1)) {
			if(word[j] == word[j + 1]) {
				j++;
			}
			else if(word[j] != word[j + 1]) {
				if(alpha[word[j + 1] - 'a'] == 1) {
					flag = -1;
					break;
				}
				else {
					alpha[word[j] - 'a'] = 1;
					j++;
				}
			}
		}

		if(flag != -1) {
			cnt++;
		}
	}

	printf("%d", cnt);
	

    return 0;
}