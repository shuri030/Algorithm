#include <iostream>
#include <stdio.h>

#define SEN_MAX 1000003

using namespace std;

int main() {

	char sen[SEN_MAX];
	int cnt = 0;
	bool check = false;
	int i = 0;
	while(1) {

		scanf("%c", &sen[i]); 
		if(sen[i] == '\n' || sen[i] == '\0') {
			break;
		}
		else if(sen[i] == ' ' && check == true) {
			check = false;
		}
		else if(sen[i] != ' ') {
			if(check == false) {
				cnt++;
			}
			check = true;
		}
		
		i++;

	}
	//printf("%d\n", strlen(sen));
	printf("%d\n", cnt);

}
