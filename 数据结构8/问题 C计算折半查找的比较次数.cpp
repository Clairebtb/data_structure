#include<iostream>
using namespace std;
int main()
{
	int n, key, a[100] = { 0 }, i = 1, count = 0;
	cin >> n;
	while (cin >> a[i])
	{
		i++;
		if (i == n+1)break;
	}
	cin >> key;
	int low = 1, high = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == key) {
			count ++; break;
		}
		else if (a[mid] > key) { high = mid - 1; count++; }
		else { low = mid + 1; count++;  }
	}
	cout << count;
}