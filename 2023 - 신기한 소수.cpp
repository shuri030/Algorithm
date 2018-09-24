#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

int number[10];
int n;
set<int> ans;
int plus_n[9] = {1, 3, 4, 5, 6, 7, 8, 9}; //7

bool is_prime(int num) {

	for(int i = 2; i <= num / 2; i++) {
		if(num % i == 0) {
			return false;
		}
	}
	return true;
}
void good_prime(int cur, int cal)
{
	if(cur >= n) {
		ans.insert(cal);
		return;
	}

	for(int i = 0; i < 8; i++) {
		cal = (cal * 10) + plus_n[i];
		if(is_prime(cal)) {
			number[cur] = plus_n[i];
			good_prime(cur + 1, cal);
		}
		cal = (cal - plus_n[i]) / 10; //다시 나누고 빼줘여야함
	}
}

int main()
{
	int prime[5] = {2, 3, 5, 7};
	
	scanf("%d", &n);

	for(int i = 0; i < 4; i++) {
		number[0] = prime[i];
		good_prime(1, prime[i]);
	}

	for(auto it = ans.begin(); it != ans.end(); it++){
		cout << *it << endl;
	}


}