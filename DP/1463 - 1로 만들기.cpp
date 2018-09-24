#include <iostream>
#include <limits.h>
#define MAX 1000010
using namespace std;

int check[MAX];
int n;
void cnt(int n) 
{
	if(n < 1) {
		return;
	}
	if(n % 3 == 0) {
		if(check[n / 3] > check[n] + 1) {
			check[n / 3] = check[n] + 1;
			cnt(n / 3);
		}
	}
	if(n % 2 == 0) {
		if(check[n / 2] > check[n] + 1) {
			check[n / 2] = check[n] + 1;
			cnt(n / 2);
		}
	}
	if(check[n - 1] > check[n] + 1) {
		check[n - 1] = check[n] + 1;
		cnt(n - 1);
	}


}
void init() 
{
	for(int i = 0; i < MAX; i++) {
		check[i] = INT_MAX / 2;
	}
}

int main()
{
	scanf("%d", &n);

	init();

	check[n] = 0;
	cnt(n);

	printf("%d", check[1]);
}
