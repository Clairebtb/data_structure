#include<iostream>
using namespace std;
int main()
{
	int n,count = 0;
	cin >> n;
	for (int cock = 0; cock <= 100; cock++){
		for (int hen = 0; hen <= 100; hen++){
			int chick = n - 5 * cock - 3 * hen;
			if (chick >= 0) {
				if (chick * 3 + hen + cock == 100)
				{
					cout << "cock:" << cock << " " << "hen:" << hen << " " << "chick:" << chick * 3 << endl; count++;
				}
			}
		}
	}
	if (count == 0) cout << "No Solution";
	return 0;
}