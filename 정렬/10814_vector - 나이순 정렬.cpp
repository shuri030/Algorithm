#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}
int main()
{	
	int N;
	vector<pair<int, string> > v;
	int age;
	string name;
		
	//pair vector를 쓰니 시간은 오래걸리지만 메모리는 덜 차지	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		cin >> age >> name;
		v.push_back(pair<int, string>(age, name));
	}

	stable_sort(v.begin(), v.end(), compare);
	//우선순위가 중복될 경우 순서가 바뀌지 않아야함(안정적)
	//그냥 sort함수는 우선순위 중복시 전과 같은 순서를 보장하지 않는다.

	for(int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	
    return 0;
}