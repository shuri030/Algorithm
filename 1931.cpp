#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	int N;
	int s, e;
	int cnt = 1;
	int start, end;
	vector<pair<int, int> > v;

	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		scanf("%d %d", &s, &e);
		v.push_back(make_pair(e, s));
	}

	sort(v.begin(), v.end());
	end = v[0].first;
	start = v[0].second;

	for(int i = 1; i < N; i++) {
		if(v[i].second >= end) {
			cnt++;
			end = v[i].first;
			start = v[i].second;
		}
	}

	printf("%d\n", cnt);
}