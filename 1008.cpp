#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

	cout.setf(ios::fixed); //
	cout.precision(9); //소수점 9자리까지 출력해라

    cout << a/b;
}
