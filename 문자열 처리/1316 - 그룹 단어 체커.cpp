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
			if(word[j] == word[j + 1]) { //같은문자면 인덱스 증가
				j++;
			}
			else if(word[j] != word[j + 1]) { //다음꺼랑 비교해서 다르면
				if(alpha[word[j + 1] - 'a'] == 1) { // 다음꺼가 이미 방문했으면
					flag = -1;
					break;
				}
				else { //아니면 방문체크
					alpha[word[j] - 'a'] = 1;
					j++;
				}
			}
		}

		if(flag != -1) { //그룹아니면 증가
			cnt++;
		}
	}

	printf("%d", cnt);
	

    return 0;
}
