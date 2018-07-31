#include <iostream>

using namespace std;

int board[10][10];
char chess[10][10];

int main()
{
	int cnt = 0;

	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			if(i % 2 != 0 && j % 2 != 0) { //행이 홀수일때 열도 홀수면
				  board[i][j] = 1; //흰색, 0은 블랙
			}
			if(i % 2 == 0 && j % 2 == 0) {
				board[i][j] = 1;
			}
		}
	}
	//체스판 입력 받기
	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			scanf(" %c", &chess[i][j]); //공백 문자를 무시하고 공백 문자가 아닌 첫 글자를 입력받습니다.
		}
	}

	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			if(board[i][j] == 1 && chess[i][j] == 'F')
				cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
