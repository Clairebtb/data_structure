#include<iostream>
using namespace std;
class MGraph
{
private:
	int arr[20][20];
	int vNum, arcNum;
public:
	int sum;
	MGraph(int r) { sum = 0; vNum = r; }
	void gMGraph(int r[], int n, int k);
	void Prim();
	int mininum(int r2[]);
};
void MGraph::gMGraph(int r[], int n, int k)
{
	for (int i = 0; i < n; i++)
		arr[k][i] = r[i];
}
void MGraph::Prim()
{
	int path[20], lowcost[20];
	for (int i = 0; i<vNum; i++)
	{
		path[i] = 0;
		lowcost[i] = arr[0][i];
	}
	lowcost[0] = 0;
	for (int i = 1; i <vNum; i++)
	{
		int k = mininum(lowcost);
		sum = lowcost[k] + sum;
		lowcost[k] = 0;
		for (int i = 0; i <vNum; i++)
		{
			if (lowcost[i] != 0 && arr[k][i]<lowcost[i])
			{
				path[i] = k;
				lowcost[i] = arr[k][i];
			}
		}
	}
}
int MGraph::mininum(int r2[])
{
	int lest = 9999; int record = 0;
	for (int i = 0; i < vNum; i++)
	{
		if (r2[i] != 0 && r2[i]<lest)	{
			lest = r2[i]; record = i;
		}
	}
	return record;
}

int main()
{
	int n;
	cin >> n;
	int r[20];
	MGraph g(n);
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			cin >> r[i];
		}
		g.gMGraph(r, n, k);
	}
	g.Prim();
	cout << g.sum;
	return 0;
}