#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

string input;

int main()
{
	int cnt = 0;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
			cnt++;
	}

	printf("%d", cnt);

	return 0;
}
