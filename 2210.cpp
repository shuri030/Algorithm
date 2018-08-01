#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int board[7][7];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int position[7] = {100000, 10000, 1000, 100, 10, 1}; 
deque<int> num; //6개의 숫자를 저장하는 디큐
vector<int> answer; //중복 없으면 정답을 넣을 벡터
set<int> ans;
int sum = 0;

bool is_in(int n) 
{
	for(int i = 0; i < answer.size(); i++) {
		if(answer[i] == n) //이미 존재
			return false;
	}

	return true;

}

void DFS(int x, int y, int depth) 
{
	if(depth == 6) {

		//숫자만들기 
		for(int k = 0; k < 6; k++) {
			sum = sum + position[k] * num[k];
		}

		ans.insert(sum);
		sum = 0;
		return;
	}

	for(int k = 0; k < 4; k++) {
		if(x + dx[k] > 0 && x + dx[k] < 6 && y + dy[k] > 0 && y + dy[k] < 6) {
			num.push_back(board[x + dx[k]][y + dy[k]]);
			DFS(x + dx[k], y + dy[k], depth + 1);
			num.pop_back();
		}
	}

}

int main()
{
	for(int i = 1; i <= 5 ; i++) {
		for(int j = 1; j <= 5; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for(int i = 1; i <= 5 ; i++) {
		for(int j = 1; j <= 5; j++) {
			num.push_back(board[i][j]);
			DFS(i, j, 1);
			num.clear();
		}
	}

	cout << ans.size() << endl;
}
