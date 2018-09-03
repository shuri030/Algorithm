#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct word {
	char c;
	int n;
	int s;

	bool operator <(const word &an) const {
		return n > an.n;
	}
};
word w[27];

int ans[27];
char input[12][12];
int num[9] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", input[i]);
	}

	for (int i = 0; i < N; i++) {
		int len = strlen(input[i]) - 1;

		for (int j = 0; j < (int)strlen(input[i]); j++) {

			w[input[i][j] - 'A'].c = input[i][j];
			w[input[i][j] - 'A'].n += num[len];
			len--;
		}
	}

	sort(w, w + 27);

	int t = 9, sum = 0;
	for (int i = 0; i < 27; i++) {

		if (w[i].n == 0) {
			break;
		}

		sum = sum + (t * w[i].n);
		t--;
	}

	printf("%d", sum);
	return 0;
}
