#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#define MAX_L 1000005

using namespace std;

int num[30];

int main() 
{
	
	char st[MAX_L];
	
	scanf("%s", st);

	for(int i = 0; i < strlen(st); i++) {
		if((st[i] >= 65) && (st[i] <= 90)) { //대문자면
			num[st[i] - 64]++;
		}
		else if((st[i] >= 97) && (st[i] <= 122)) { //소문자면
			num[st[i] - 96]++;
		}
	}

	int max_a = 0, flag = 0;
	char ans;
	for(int i = 1; i <= 26; i++) {
		if(num[i] > max_a) {
			max_a = num[i];
			ans = i + 64;
		}
	}

	for(int i = 1; i <= 26; i++) {
		if(num[i] == max_a) {
			flag++;
		}
	}

	if(flag != 1) {
		printf("?");
	}
	else if(flag == 1) {
		printf("%c", ans);
	}

    return 0;
}