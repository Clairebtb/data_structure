#include <iostream>
#include <string.h>
#include <algorithm>
#include<iomanip>
using namespace std;
int card[4];
int operate(int s, int m, int n)
{
	if (s == 1) return m + n;
	else if (s == 2) return m - n;
	else if (s == 3) return m*n;
	else if (s == 4)
	{
		if (n != 0 && m%n == 0)
			return m / n;
		else
			return 100000;
	}
}
void cal(int i, int j, int k, int &count)
{
	int temp1 = operate(i, card[0], card[1]);
	int temp2 = operate(j, temp1, card[2]);
	int temp3 = operate(k, temp2, card[3]);
	if (temp3 == 24 || temp3 == -24)
		count++;
}
void cal2(int i, int j, int k, int &count)
{
	int temp1 = operate(i, card[0], card[1]);
	int temp2 = operate(k, card[2], card[3]);
	int temp3 = operate(j, temp1, temp2);
	if (temp3 == 24 || temp3 == -24)
		count++;
}
int main()
{
	char c[4];
	int count = 0;
	int i = 0;
	while (cin >> c[i]) {
		if (c[i] == 'A') card[i] = 1;
		if (c[i] == 'J') card[i] = 11;
		if (c[i] == 'Q') card[i] = 12;
		if (c[i] == 'K') card[i] = 13;
		else card[i] = int(c[i]) - 48;
		i++;
	}
	/*for (int i = 0; i < 4 && cin >> c[i]; i++)
	{
		if (c[i] == 'A')
		{
			card[i] = 1;
			continue;
		}
		else if (c[i] == 'J')
		{
			card[i] = 11;
			continue;
		}
		else if (c[i] == 'Q')
		{
			card[i] = 12;
			continue;
		}
		else if (c[i] == 'K')
		{
			card[i] = 13;
			continue;
		}

		else if (c[i] < '11'&&c[i] > '1')
			card[i] = c[i] - '0';
	}*/
	sort(card, card + 4);
	do {
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				for (int k = 1; k <= 4; k++)
				{
					cal(i, j, k, count);
					cal2(i, j, k, count);
					if (count >= 1) break;
				}
				if (count >= 1) break;
			}
			if (count >= 1) break;
		}
	} while (next_permutation(card, card + 4) && !count);
	if (count >= 1)
		cout << "Y";
	else
		cout << "N";
	return 0;
}
























/*  24µ„
#include <iostream>  
#include <cstdio>  
#include <math.h>  
using namespace std;
int a[6];
bool d(int x) {
	if (x == 3) {
		if (24 == a[x])
			return true;
		return false;
	}
	int i, j;
	for (i = x; i < 4; i++)
		for (j = i + 1; j < 4; j++) {
			int le = a[i], ri = a[j];
			a[i] = a[x];
			a[j] = le + ri;    if (d(x + 1))  return true;
			a[j] = le - ri;     if (d(x + 1))  return true;
			a[j] = le*ri;     if (d(x + 1))  return true;
			a[j] = ri - le;     if (d(x + 1))  return true;
			if (ri != 0 && le%ri == 0) {
				a[j] = le / ri; if (d(x + 1))  return true;
			}
			if (le != 0 && ri%le == 0) {
				a[j] = ri / le; if (d(x + 1))  return true;
			}
			a[i] = le;
			a[j] = ri;
		}
	return false;
}
	 int main()
	 {
		 char arr1[4];
		 int arr[4];
		 int i = 0;
		 while (cin >> arr1[i]) {
			 if (arr1[i] == 'A') arr[i] = 1;
			 if (arr1[i] == 'J') arr[i] = 11;
			 if (arr1[i] == 'Q') arr[i] = 12;
			 if (arr1[i] == 'K') arr[i] = 13;
			 else arr[i] = int(arr1[i]) - 48;
			 i++;
		 }
		 for (int j = 0; j < 4; j++) {
			 a[i] = arr[i];
		 }
		 if (d(0))cout << 'F';
		 else cout << 'Y';
	 }

	 */



/*  24µ„  by wxp
#include<iostream>
using namespace std;

int n = 0;
void c(float x, float y, float z, float w)
{
	int count = 0;
	if (x + y + z + w == 24)   count++;
	else if (x + y + z - w == 24) count++;
	else if ((x + y)*(z + w) == 24) count++;
	else if ((x - y)*(z + w) == 24) count++;
	else if ((x - y)*(z - w) == 24) count++;
	else if ((x + y + z)*w == 24) count++;
	else if ((x - y - z)*w == 24) count++;
	else if ((x + y - z)*w == 24) count++;
	else if ((x*y*z) / w == 24) count++;
	else if ((x*y)*(z + w) == 24) count++;
	else if ((x*y)*(z - w) == 24) count++;
	else if ((x*y)*z - w == 24) count++;
	else if ((x*y)*z + w == 24) count++;
	else if (x*y*z*w == 24) count++;
	else if ((x + y) + (z / w) == 24) count++;
	else if ((x + y)*(z / w) == 24) count++;
	else if ((x*y) + z + w == 24) count++;
	else if ((x*y) + z - w == 24) count++;
	else if ((x*y) - (z / w) == 24) count++;
	else if ((x*y) + (z / w) == 24) count++;
	else if ((x*y) - z - w == 24) count++;
	else if ((x*y) + (z*w) == 24) count++;
	else if ((x*y) - (z*w) == 24) count++;
	else if ((x*y) / (z*w) == 24) count++;
	else if ((x*y) / (z - w) == 24) count++;
	else if ((x*y) / (z + w) == 24)count++;
	if (count == 0) n++;
}

int main()
{
	char arr1[4];
	int arr[4];
	int i = 0;
	while(cin >> arr1[i]){
		if (arr1[i] == 'A') arr[i] = 1;
		if (arr1[i] == 'J') arr[i] = 11;
		if (arr1[i] == 'Q') arr[i] = 12;
		if (arr1[i] == 'K') arr[i] = 13;
		else arr[i] = int(arr1[i]) - 48;
		i++;
	}
	int x, y, z, w;
	x = arr[0];
	y = arr[1];
	z = arr[2];
	w = arr[3];
//∏ƒ±‰‘ÀÀ„À≥–Ú
	c(x, y, z, w);
	c(x, y, w, z);
	c(x, z, w, y);
	c(x, z, y, w);
	c(x, w, y, z);
	c(x, w, z, y);
	c(y, x, z, w); 
	c(y, x, w, z); 
	c(y, z, x, w);
	c(y, z, w, x);
	c(y, w, z, x); 
	c(y, w, x, z);
	c(z, x, y, w); 
	c(z, x, w, y); 
	c(z, y, w, x);
	c(z, y, x, w);
	c(z, w, x, y);
	c(z, w, y, x);
	c(w, x, y, z);
	c(w, x, z, y);
	c(w, y, z, x);
	c(w, y, x, z); 
	c(w, z, x, y); 
	c(w, z, y, x);
	if (n == 24)
		cout << "N";
	else cout << "Y";
	return 0;
}
*/





/*∂˛≤Ê≈≈–Ú ˜
#include<iostream>
using namespace std;
int du = 0;

struct Node
{
	int data;
	Node*lchild;
	Node*rchild;
};

class tree
{
private:

public:
	Node *root;
	tree()
	{	root = NULL;}
	void getdu(Node*a);
	void getTree(Node *&a, int b);
};

void tree::getdu(Node*a)
{

	if (a)
	{
		if (a->rchild&&a->lchild) { du++; }
		getdu(a->lchild);
		getdu(a->rchild);
	}

}
void tree::getTree(Node *&a, int b)
{
	if (a == NULL)
	{
		a = new Node;
		a->data = b;
		a->rchild = a->lchild = NULL;
		return ;
	}
	if (b >= a->data)
	{
		getTree(a->rchild, b);

	}
	else
		getTree(a->lchild, b);


}

int main()
{
	tree t;
	int n;
	cin >> n;
	int a;
	while (cin >> a)
	{
		t.getTree(t.root, a);
	}
	t.getdu(t.root);

	cout << du + 1 << " " << n - 2 * du - 1 << " " << du;

}
*/


/*≈–∂œ «∑ÒŒ™∂˛≤Ê≈≈–Ú ˜  by wxp
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct Node
{
	char data;
	struct Node*lchild;
	struct Node* rchild;
};

class Tree
{
private:
	void create(Node *& R, char data[], int i, int n);
	void Release(Node *r);
public:
	Node * root;
	Tree(char data[], int length);
	~Tree();
	int shendu(Node*r);
	bool panduan(Node*r);



};

void  Tree::create(Node *& R, char data[], int i, int n)
{
	if (i <= n&&data[i - 1] != '0')
	{
		R = new Node;
		R->data = data[i - 1];
		create(R->lchild, data, 2 * i, n);
		create(R->rchild, data, 2 * i + 1, n);


	}
	else R = NULL;

}



Tree::Tree(char data[], int length)
{
	create(root, data, 1, length);
}

void Tree::Release(Node *r)
{
	if (r)
	{
		Release(r->lchild);
		Release(r->rchild);
		delete r;

	}
}

 Tree::~Tree()
{
	 Release(root);
}
 int Tree::shendu(Node*r)
 {
	 if (r == NULL)return 0;
	 return shendu(r->rchild) > shendu(r->lchild) ? shendu(r->rchild) + 1 : shendu(r->lchild) + 1;

 }
 bool Tree::panduan(Node*r)
 {
	 if (r == NULL)
		 return true;
	 if (abs(shendu(r->rchild) - shendu(r->lchild)) > 1) return false;
	 return panduan(r->rchild) && panduan(r->lchild);
	 
 }




int main()
{
	char data[20];
	cin >> data;
	int length = strlen(data);
	Tree a(data, length);
	if (a.panduan(a.root)) { cout << "True";}
	else cout << "False"; 
	
	
	return 0;




}*/

























/*  π˛∑Ú¬¸ ˜
#include <iostream>
#include<string>
using std::string;
using namespace std;
struct hnode
{
	int weight;
	int parents;
	int lchild;
	int rchild;
};
struct hcode
{
	char data;
	char code[100];
};
class huffman
{
private:
	hnode*htree;

public:
	hcode*hcodetable;
	void createhtree(int a[], int n);
	void createcodetable( int n);
	void selectmin(int &x, int & y, int z, int i);
	void reverse(char a[]);
};
void huffman::createhtree(int a[] , int n)
{
	htree = new hnode[2 * n - 1];
	for (int i = 0; i < n; i++)
	{
		htree[i].weight = a[i];
		htree[i].lchild = htree[i].rchild = htree[i].parents = -1;

	}
	int x=0, y=0;
	for (int i = n; i < 2 * n - 1; i++) {
		selectmin(x, y, 0, i);
		//cout << x << y << htree[x].weight << htree[y].weight<<endl;
		htree[x].parents = htree[y].parents = i;
		htree[i].weight = htree[x].weight + htree[y].weight;
		htree[i].lchild = x;
		htree[i].rchild = y;
		htree[i].parents = -1;
	}
}
void huffman::createcodetable(int n)
{
	hcodetable = new hcode[n];
	
	for (int i = 0; i < n; i++)
	{
		int child = i;
		int parent = htree[i].parents;
		int k = 0;
		while (parent != -1)
		{
			if (child == htree[parent].lchild)
				hcodetable[i].code[k] = '0';
			else
				hcodetable[i].code[k] = '1';
			k++;
			child = parent;
			parent = htree[child].parents;
		}
		hcodetable[i].code[k] = '\0';
		//reverse(hcodetable[i].code);
	}
}
void huffman::reverse(char a[])
{
	int n = sizeof(a);
	char k;
	for (int i = 0; i < n; i++) {
		k = a[n - i-1];
		a[n - i - 1] = a[i];
		a[i] = k;
	}
}
void huffman::selectmin(int &x, int &y, int z, int j)
{
	int i;
	for (i = z; i <= j; i++) {
		if (htree[i].parents == -1) {
			x = y = i; break;
		}
	}
	for (; i < j; i++) {
		if (htree[i].parents == -1) {
			if (htree[i].weight < htree[x].weight) {
				y = x; x = i;
			}
			else if ((x == y)||(htree[i].weight < htree[y].weight))
			{
				y = i;
			}
		}
	}
	/*for (int j = z; j < i-1; j++) {
		for (int k = z; k < i - 1 - j; k++)  
		{
			if (htree[k].weight > htree[k+1].weight)
			{
				int temp = htree[k].weight;
				htree[k].weight = htree[k + 1].weight;
				htree[k + 1].weight= temp;
			}
		}
	}
	while (htree[z].parents!=-1)
	{
		z++;
	}
	x = z;
	y = z+1;*/
/*}
int main()
{
	int n = 0;
	cin >> n;
	int a[20] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	huffman t;
	t.createhtree(a, n);
	t.createcodetable(n);
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		len += a[i]*(strlen(t.hcodetable[i].code));
		//cout << a[i]<<" "<< strlen(t.hcodetable[i].code)<<" "<< t.hcodetable[i].code<<" "<<len<<endl;
	}
	cout << len;

}
*/

/*#include <iostream>
#include <list>
using std::list;
using namespace std;
int main()
{
	list<int> data;
	int num, t;
	cin >> num;
	for (int i = 0; i<num; i++) 
	{
		cin >> t;
		data.push_back(t);
	}
	int s = 0;
	while ( data.end()!= ++(data.begin()))
	{
		data.sort();
		t = *data.begin();
		data.pop_front();
		t += *data.begin();
		data.pop_front();
		data.push_back(t);
		s += t;
	}
	cout << s;
	return 0;
}*/


















/*  ”…«∞–Ú÷––ÚΩ® ˜ ‰≥ˆ∫Û–Ú≤„–Ú
#include <iostream>
#include<string>
using std::string;
using namespace std;
struct node
{
	char data;
	node*lchild;
	node*rchild;
};
class tree
{
private:
	void create(node*&r, string a,string b);
	void release(node*r);
public:
	node*root=NULL;
	tree(string a,string b);
	bool notable(string a, string b);
	void postorder(node*r);
	void levelorder(node*r);
	~tree();
};
void tree::create(node*&r, string a,string b)
{
	if (a.size() == 0) { r = NULL; }
	else {
		char rootnode = a[0];
		int index = b.find(rootnode);
		string lchb = b.substr(0, index);
		string rchb = b.substr(index + 1);
		int lchlen = lchb.size();
		int rchlen = rchb.size();
		string lcha = a.substr(1, lchlen);
		string rcha = a.substr(lchlen + 1);
		if (notable(rcha, lchb) == true) 
		{ cout << "error";
		exit(0); }
		else {
			r = new node;
			if (r != 0) {
				r->data = rootnode;
				create(r->lchild, lcha, lchb);
				create(r->rchild, rcha, rchb);
			}
		}
	}
}
bool tree::notable(string a, string b)
{
	int i = a.find_last_of(b,0);
	if (i==-1)
		return false;
	else return true;
}
tree::tree(string a, string b)
{
	create(root, a, b);
}

void tree::release(node*r)
{
	if (r) {
		release(r->lchild);
		release(r->rchild);
		delete(r);
	}
}
tree::~tree()
{
	release(root);
}
void tree::postorder(node*r)
{
	if (r != NULL) {
		
		postorder(r->lchild);
		postorder(r->rchild);
		 cout << r->data; 
	}
}
void tree::levelorder(node*r)
{
	node*queue[100];
	int f = 0, n = 0;
	if (r != NULL)queue[++n] = r;
	while (f != n) {
		node*p = queue[++f];
    	 cout << p->data; 
		if (p->lchild != NULL)queue[++n] = p->lchild;
		if (p->rchild != NULL)queue[++n] = p->rchild;
	}

}
int main()
{
	string a, b;
	cin >> a >> b;
	tree t(a,b);
	t.postorder(t.root);
	cout << endl;
	t.levelorder(t.root);
}
*/
























/*ππΩ®∂˛≤Ê ˜
#include <iostream>
#include<cstring>
using namespace std;
struct node
{
	char data;
	node*lchild;
	node*rchild;
};
class tree
{
private:
	void create(node*&r, char data[], int i ,int n);
	void release(node*r);
public:
	node*root;
	tree(char data[], int n);
	void preorder(node*r);
	void levelorder(node*r);
	~tree();
};
void tree::create(node*&r, char data[], int i, int n)
{
	if (i <= n&&data[i - 1]) {
		r = new node;
		r->data = data[i - 1];
		create(r->lchild, data, 2 * i, n);
		create(r->rchild, data, 2 * i + 1, n);
	}
	else r = NULL;
}
tree::tree(char data[], int n)
{
	create(root, data, 1, n);
}
void tree::release(node*r)
{
	if (r) {
		release(r->lchild);
		release(r->rchild);
		delete(r);
	}
}
tree::~tree()
{
	release(root);
}
void tree::preorder(node*r)
{
	if (r != NULL) {
		if (r->data != '0') { cout << r->data; }
		preorder(r->lchild);
		preorder(r->rchild);

	}
}
void tree::levelorder(node*r)
{
	node*queue[100];
	int f = 0, n = 0;
	if (r != NULL)queue[++n] = r;
	while (f != n) {
		node*p = queue[++f];
		if (p->data != '0') { cout << p->data; }
		if (p->lchild != NULL)queue[++n] = p->lchild;
		if (p->rchild != NULL)queue[++n] = p->rchild;
	}

}

int main()
{
	char a[100];
	cin >> a;
	int length = strlen(a);
	tree t(a, length);
	t.preorder(t.root);
	cout << endl;
	t.levelorder(t.root);
}

*/



























/*   ≈–∂œ «∑Ò∆Ω∫‚∂˛≤Ê ˜
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct Node
{
	char data;
	struct Node*lchild;
	struct Node* rchild;
};
class Tree
{
private:
	void create(Node *& R, char data[], int i, int n);
public:
	Node * root;
	Tree(char data[], int length);
	~Tree();
	void Release(Node *r);
	int depth(Node*r);
	bool isbalance(Node*r);
};
void  Tree::create(Node *& R, char data[], int i, int n)
{
	if (i <= n&&data[i - 1] != '0')
	{
		R = new Node;
		R->data = data[i - 1];
		create(R->lchild, data, 2 * i, n);
		create(R->rchild, data, 2 * i + 1, n);
	}
	else R = NULL;
}
Tree::Tree(char data[], int length)
{
	create(root, data, 1, length);
}
Tree::~Tree()
{
	Release(root);
}
bool Tree::isbalance(Node*r)
{
	if (r == NULL)
		return true;
	if (abs(depth(r->rchild) - depth(r->lchild)) > 1) return false;
	return isbalance(r->rchild) && isbalance(r->lchild);

}
int Tree::depth(Node*r)
{
	if (r == NULL)return 0;
	return depth(r->rchild) > depth(r->lchild) ? depth(r->rchild) + 1 : depth(r->lchild) + 1;

}
void Tree::Release(Node *r)
{
	 if (r)
	 {
		 Release(r->lchild);
		 Release(r->rchild);
		 delete r;

	 }
}
int main()
{
	char data[20];
	cin >> data;
	int len = strlen(data);
	Tree a(data, len);
	if (a.isbalance(a.root)) 
	{ cout << "True";}
	else cout << "False"; 
	return 0;
}
*/






/*
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct Node
{
	char data;
	struct Node*lch;
	struct Node*rch;
};

class Tree
{
private:
	void create(Node *& R, char data[], int i, int n);
	void Release(Node *r);
public:
	Node * root;
	Tree(char data[], int length);
	~Tree();
	int depth(Node*r);
	bool isbalance(Node*r);
};

void  Tree::create(Node *& R, char data[], int i, int n)
{
	if (i <= n&&data[i - 1] )
	{
		R = new Node;
		R->data = data[i - 1];
		create(R->lch, data, 2 * i, n);
		create(R->rch, data, 2 * i + 1, n);
	}
	else R = NULL;
}

Tree::Tree(char data[], int length)
{
	create(root, data, 1, length);
}

void Tree::Release(Node *r)
{
	if (r)
	{
		Release(r->lch);
		Release(r->rch);
		delete r;

	}
}

Tree::~Tree()
{
	Release(root);
}

bool Tree::isbalance(Node*r)
{
	if (r == NULL)
		return true;
	if (abs(depth(r->rch) - depth(r->lch)) > 1) return false;
	return isbalance(r->rch) && isbalance(r->lch);
}
int Tree::depth(Node*r)
{
	if (r == NULL)return 0;
	return depth(r->rch) > depth(r->lch) ? depth(r->rch) + 1 : depth(r->lch) + 1;
}

int main()
{
	char data[20];
	cin >> data;
	int length = strlen(data);
	Tree T(data, length);
	if (T.isbalance(T.root)) { cout << "True"; }
	else cout << "False";
	return 0;
}
*/


/*
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[1000] = { '0' };
	for (int i = 0; i < 1000; i++)a[i] = '0';
	//cout << a[10];
	cin >> a;
	int i = strlen(a);
	a[i] = '0';
	//cout << a[0] << a[1] << i;
	for (int j = 1; j < i ; j++) {
		//cout << a[j * 2 - 1]<< a[j * 2]<< a[4 * j - 1]<< a[(2 * j) * 2] <<endl;
			if (a[j * 2-1] == '0' && (a[(2 * j+1 ) * 2-1] != '0' || a[(2 * j + 1) * 2 ] != '0')) {
				cout << "False";
				exit(0);
			}
			if (a[j * 2 ] == '0' && (a[4*j-1] != '0' || a[(2 * j) * 2 ] != '0')) {
				cout << "False";
				exit(0);
			}
	}
	cout << "True";
}
*/