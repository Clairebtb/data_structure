#include<iostream>
using namespace std;

class graph
{
private:
	int vNum, arcNum;
	bool visited[20];
	int top[20];
	int arcs[20][20];
	int count;
public:
	graph(int n);
	void schap(int a[], int n, int e);
	void DFS(int v);
	void BFS(int v);
	void empty()
	{
		for (int i = 0; i<20; i++)
		{
			visited[i] = false;
		}
		count = 0;
	};
};
void graph::DFS(int v)
{
	if (count == vNum - 1) {
		cout << top[v];
	}
	else { cout << top[v] << " "; }
	visited[v] = true; count++;
	int j = 0;
	while (j < vNum)
	{
		if (arcs[v][j] != 0 && visited[j] == false) DFS(j);
		else j = j + 1;
	}
}
void graph::BFS(int v)
{
	int queue[20] = { 0 };
	int f = 0, r = 0;
	queue[++r] = v;
	cout << v << " "; visited[v] = true;
	while (f != r)
	{
		v = queue[++f];
		for (int i = 0; i < vNum; i++)
		{
			if (arcs[v][i] != 0 && visited[i] == false)
			{
				queue[++r] = i;
				if (count == vNum - 2)
				{
					cout << top[i];
				}
				else cout << top[i] << " ";
				visited[i] = true;
				count++;
			}
		}
	}
}

graph::graph(int n)
{
	for (int i = 0; i<20; i++)
	{
		visited[i] = false;
		top[i] = i;
	}
	vNum = n;
	count = 0;
}

void graph::schap(int a[], int h, int column)
{
	for (int i = 0; i < column; i++){
		arcs[h][i] = a[i];
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[20] = { 0 };
	graph g(n);
	for (int j = 0; j < n; j++){
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		g.schap(arr, j, n);
	}
	g.DFS(0);
	cout << endl;
	g.empty();
	g.BFS(0);
	return 0;
}