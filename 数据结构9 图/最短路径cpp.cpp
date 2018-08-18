#include<iostream>
using namespace std;
int MAX = 9999;
class MGraph
{
public:
	int arcs[20][20];
	int price1[20][20];


	int vNum, arcNum;


	MGraph(int n, int e);
	void gMGraph(int n, int k, int price, int path);



};
MGraph::MGraph(int n, int e)
{
	vNum = n;
	arcNum = e;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arcs[i][j] = MAX;
			price1[20][20] = MAX;
		}
	}

}

void MGraph::gMGraph(int n, int k, int price, int path)
{
	arcs[n - 1][k - 1] = path;
	arcs[k - 1][n - 1] = path;
	price1[n - 1][k - 1] = price;
	price1[k - 1][n - 1] = price;
}

int FindMin(int Disk[], int pprice[], bool s[], int n)
{
	int k = 0, min = MAX;
	for (int i = 0; i < n; i++)
	{
		if (!s[i] && min > Disk[i])
		{
			min = Disk[i]; k = i;
		}
		if (!s[i] && min == Disk[i])
		{
			if (pprice[i]<pprice[k]) { min = Disk[i]; k = i; }
		}
	}
	if (min == MAX) return -1;
	return k;

}

void ShortPath(MGraph G, int v, int Disk[], int Path[], int pprice[])
{
	bool s[20] = { false };
	for (int i = 0; i < G.vNum; i++)
	{
		Disk[i] = G.arcs[v][i];
		pprice[i] = G.price1[v][i];
		if (Disk[i] != MAX) Path[i] = v;
		else Path[i] = -1;
	}
	s[v] = true; Disk[v] = pprice[v] = 0;
	for (int i = 0; i < G.vNum; i++)
	{
		if ((v = FindMin(Disk, pprice, s, G.vNum)) == -1)
			return;
		s[v] = true;
		for (int j = 0; j<G.vNum; j++)
			if (!s[j] && (Disk[j]>G.arcs[v][j] + Disk[v]))
			{
				Disk[j] = G.arcs[v][j] + Disk[v]; Path[j] = v;
				pprice[j] = G.price1[v][j] + pprice[v];
			}
	}
}

int main()
{
	int n, v;
	cin >> n >> v;
	MGraph sample(n, v);
	int f, r, path, price;
	for (int i = 0; i < v; i++)
	{
		cin >> f >> r >> path >> price;
		sample.gMGraph(f, r, price, path);
	}
	int c1, c2;
	while (1) {
		cin >> c1 >> c2;
		if (c1 == c2&&c1 == 0)break;
		int a1[20], b[20], b1[20];
		ShortPath(sample, c1 - 1, a1, b, b1);
		cout << a1[c2 - 1] << " " << b1[c2 - 1];
	}
	return 0;
}
