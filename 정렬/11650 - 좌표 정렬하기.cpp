#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if(a.first != b.first) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main()
{	
	int N, a, b;
	vector<pair<int, int> > v;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end(), compare);

	for(int i = 0; i < N; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	
    return 0;
}