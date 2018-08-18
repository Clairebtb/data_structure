#include<iostream>
using namespace std;
int main()
{
	int n, p, m, k, a[100] = { 0 }, b[100] = { 0 };
	cin >> n >> p >> m;
	for (int i = 0; i<n; i++)
		cin >> a[i];
	cin >> k;
	for (int i = 0; i < n; i++) {
		int d = 1, ADDi = a[i] % p;
		while (1) {
			if (b[ADDi] == 0) { b[ADDi] = a[i]; break; }
			else ADDi = (ADDi + d) % m; d++;
		}
	}
	int count = 1, d1 = 0;
	while (1) {
		if (b[(k + d1) % p] == k || b[(k + d1) % p] == 0)break;
		else { d1++; count++; }
	}
	cout << count;
	return 0;
}