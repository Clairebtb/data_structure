/*#include<iostream> 
using namespace std;
int n = 2, h[100] = { 0 }, arr[100] = { 0 }, k = 1, g;
int main()
{
	arr[1] = 1;
	while (cin >> h[n])
		n++;
	n--;
	for (int i = 2; i <= n; i++)
	{
		g = 1;
		for (int j = 1; j <= i - 1; j++)
		{
			if (h[i]<h[j])
				if (arr[j] + 1>g) g = arr[j] + 1;
			arr[i] = g;
		}
	}
	for (int i = 1; i <= n; i++)
		if (arr[i]>k) k = arr[i];
	cout << k;
	return 0;
}*/
#include<iostream>
using namespace std;
int getmax(int a[], int n)
{
	int num[30] = { 0 };
	for (int i = 0; i < n; i++){
		num[i] = 1;
		for (int j = 0; j < i; j++){
			if (a[j] >= a[i] && num[j] + 1 >= num[i])
				num[i] = num[j] + 1;
		}
	}
	int max = num[0];
	for (int i = 1; i < n; i++){
		if (max < num[i])max = num[i];
	}
	return max;
}
int main()
{
	int a[30];
	int i = 0;
	while (cin >> a[i])
		i++;
	int M = getmax(a, i);
	cout << M;
	return 0;
}