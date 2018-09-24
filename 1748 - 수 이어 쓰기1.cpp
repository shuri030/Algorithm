#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	int sum = 0;
	
	scanf("%d", &n);

	for(int i = 1; i <= n; i*=10) {
		sum += (n - i + 1);
	}

	printf("%d", sum);
  
   return 0;
}