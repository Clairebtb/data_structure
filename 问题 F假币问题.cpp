/*#include<iostream>
using namespace std;
int main() {
	int a[10000], i = 0, count = 0;
	while (cin >> a[i]) { 
		if (a[i] == 0)break;
		i++;
	}
	for (int j = 0; j < i; j++) {
		count = 0;
	while((a[j]/2) != 0) {
			count++;
			a[j] /= 2;
		}
		cout << count << endl;
	}
}*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	while (1)
	{
		int a;
		cin >> a;
		if (a == 0)break;
		int s = ceil(log(a) / log(3));
		cout << s << endl;
	}
}