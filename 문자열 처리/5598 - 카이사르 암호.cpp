#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C') {
			printf("%c", input[i] + 23);
		}
		else {
			printf("%c", input[i] - 3);
		}
	}

	return 0;
}
