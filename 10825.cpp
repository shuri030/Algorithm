#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person {
	string name;
	int kor;
	int eng;
	int math;

	bool operator <(const person &an) const {
		if(kor != an.kor) {
			return kor > an.kor;
		}
	else {
		if(eng == an.eng) {
			if(math == an.math) {
				return name < an.name;
			}
			return math > an.math;
		}
		return eng < an.eng;
	}

	}
};
person p[100000];

int main()
{	
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		cin >> p[i].name >> p[i].kor >> p[i].eng >> p[i].math;
	}

	stable_sort(p, p + N);

	for(int i = 0; i < N; i++) {
		cout << p[i].name << "\n";
	}
	
    return 0;
}