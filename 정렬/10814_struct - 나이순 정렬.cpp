#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
	int age;
	char name[101];

	bool operator <(const person &another) const {
		return this->age < another.age;
	}
};
person p[100001];

int main()
{	
	int N;
	scanf("%d", &N);
	
	//구조체 배열을 쓰는 것이 시간이 덜 걸렸지만 메모리는 많이 차지
	for(int i = 0; i < N; i++) {
		scanf("%d %s", &p[i].age, p[i].name);
	}

	stable_sort(p, p + N);
	//우선순위가 중복될 경우 순서가 바뀌지 않아야함(안정적)
	//그냥 sort함수는 우선순위 중복시 전과 같은 순서를 보장하지 않는다.

	for(int i = 0; i < N; i++) {
		printf("%d %s\n", p[i].age, p[i].name);
	}
	
    return 0;
}