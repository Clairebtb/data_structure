#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	int a[100], b[100],k;
	int i = 0;
	while (cin >> a[i] >> b[i]) { i++; }
	for (int j = 0; j < i; j++) {
		k = abs(a[j] - b[j]);
		a[j] = a[j] > b[j] ? b[j] : a[j];
		if (a[j] == (int)(k*(sqrt(double(5)) + 1) / double(2)))cout << '0' << endl;
		else cout << '1' << endl;
	}
}