#include <iostream>
using namespace std;
int main()
{
	int n, m=0, i;
	cin >> n;
	int a[100], b[6] = { 100,50,20,5,2,1 };
	for (i = 0; i < n+1; i++) {
		cin >> a[i];
		if (a[i] == 0)break;
	}
	for (i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			while (a[i] - b[j] >= 0) {
				m++;
				a[i] -= b[j];
			}
		}
	}
	cout << m;
}