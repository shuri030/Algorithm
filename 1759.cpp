#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

int L, C;

char word[20];
char pwd[20];

int check()
{
	int con = 0, vo = 0;

	for(int i = 0; i < L; i++) {
		if((pwd[i] == 'a') || (pwd[i] == 'e') || (pwd[i] == 'i') || (pwd[i] == 'o') || (pwd[i] == 'u')) {
			vo++;
		}
		else {
			con++;
		}
	}

	if(vo >= 1 && con >= 2) {
		return 1;
	}
	else {
		return 0;
	}
}

//암호 생성
void make_pwd(int n, int cur)
{
	
	if(n >= L) {
		//자음모음검사
		if(check() == 1) {
			for(int i = 0; i < L; i++) {
				printf("%c", pwd[i]);
			}
			printf("\n");
		
		}
		return;
	}
	if(n == 0) {
		if(cur > C - L) 
			return;
	}
	

	for(int i = cur; i < C; i++) {
		pwd[n] = word[i];
		make_pwd(n + 1, i + 1);
	}

	return;
}

int main(void)
{
	scanf("%d %d", &L, &C);

	for(int i = 0; i < C; i++) {
		scanf(" %c", &word[i]);
	}

	char tmp;
	//정렬
	for(int i = 0; i < C - 1; i++) {
		for(int j = i + 1; j < C; j++) {
			if(word[i] > word[j]) {
				tmp = word[i];
				word[i] = word[j];
				word[j] = tmp;
			}
		}
	}
	make_pwd(0, 0);

	return 0;
}
