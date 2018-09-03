#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;

int K, N;
vector<pair<int, char> > p;

int bomb(int k, char ans)
{
	if (ans == 'T') { //맞았으면
		if (k == 8) { return 1;  }
		else { return k + 1;  }
	}

	else if (ans == 'N') { //틀렸으면
		return k; //원래 가지고 있던 사람이 폭탄 들고있다.
	}

	else if (ans == 'P') { //스킵했으면
		return k; //원래 가지고 있던 사람이 폭탄 들고있다.
	}
}
int main()
{
	int t, z;

	scanf("%d", &K);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %c", &t, &z);
		p.push_back({ t, z });
	}

	int cur_time = 0;
	for (int i = 0; i < N; i++) {
		cur_time += p[i].first;

		if (cur_time >= 210) { //3분 30초
			printf("%d", K);
			break;
		}
		K = bomb(K, p[i].second);
	}

	return 0;
}
