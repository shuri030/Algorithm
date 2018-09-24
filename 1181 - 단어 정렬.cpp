#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

string word[20000];
int n;

bool compare(string a, string b)
{
	if(a.length() < b.length()) { //길이가 짧은 단어부터 우선순위를 준다
		return 1;
	}
	else if(a.length() > b.length()) {
		return 0;
	}
	else { //같으면 사전 순
		return a < b;
	}
}

int main()
{	
	int N, num;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> word[i];
	}

	sort(word, word + N, compare);

	for(int i = 0; i < N; i++) {
		if(i > 0 && word[i] == word[i - 1]) { continue; } //같으면 출력하지마
		cout << word[i] << "\n";
	}
	
    return 0;
}