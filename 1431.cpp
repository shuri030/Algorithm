#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

string word[20000];
int n;

int get_sum(string s)
{
	int sum = 0;
	for(int i = 0; i < s.length(); i++) {
		if((s[i] - '0' >= 0) && (s[i] - '0' <= 9)) { //숫자만
			sum += s[i] - '0';
		}
	}

	return sum;
}
bool compare(string a, string b)
{
	if(a.length() != b.length()) { //길이가 다르면 짧은 것 먼저
		return a.length() < b.length();
	}
	else  { //같으면 자리수의 합 비교
		int aSum = get_sum(a);
		int bSum = get_sum(b);

		if(aSum != bSum) 
			return aSum < bSum;
		else 
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
		cout << word[i] << "\n";
	}
	
    return 0;
}