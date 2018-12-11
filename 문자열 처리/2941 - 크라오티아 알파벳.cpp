#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	char alpha[102];
	scanf("%s", alpha);

	int s_len = strlen(alpha);
	int i = 0, ans = 0;

	while(i < s_len) {
		if (alpha[i] == 'c') {
			if ((alpha[i + 1] == '=') || (alpha[i + 1] == '-')) {
				ans++;
				i = i + 2;
				continue;
			}
			ans++;
			i = i + 1;
		}
		else if (alpha[i] == 'd') {
			if (alpha[i + 1] == '-') {
				ans++;
				i = i + 2;
				continue;
			}
			else if((alpha[i + 1] == 'z') && (alpha[i + 2] == '=')) {
				ans++;
				i = i + 3;
				continue;
			}
			ans++;
			i = i + 1;
		}
		else if (alpha[i] == 'l') {
			if (alpha[i + 1] == 'j') {
				ans++;
				i = i + 2;
				continue;
			}
			ans++;
			i = i + 1;
		}
		else if (alpha[i] == 'n') {
			if (alpha[i + 1] == 'j') {
				ans++;
				i = i + 2;
				continue;
			}
			ans++;
			i = i + 1;
		}
		else if (alpha[i] == 's') {
			if (alpha[i + 1] == '=') {
				ans++;
				i = i + 2;
				continue;
			}
			ans++;
			i = i + 1;
		}
		else if (alpha[i] == 'z') {
			if (alpha[i + 1] == '=') {
				ans++;
				i = i + 2;
				continue;
			}
			ans++;
			i = i + 1;
		}
		else {
			ans++;
			i = i + 1;
		}
	}

	printf("%d", ans);

	return 0;
}
