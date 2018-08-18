#include<iostream>
using namespace std;

class binode
{
public:
	int data;
	binode*lch;
	binode*rch;
	binode() :lch(NULL), rch(NULL) {};
};
class bst
{
public:
	bst(int r[], int n);
	~bst();
	void destroy(binode*r);
	void insert(binode*&r, binode*s);
	binode*search(binode*r, int key);
	binode*root;
	int count = 0;
private:

};
binode*bst::search(binode*r, int key)
{
	count++;
	if (r == NULL)return NULL;
	if (key == r->data)return r;
	else if (key < r->data)return search(r->lch, key);
	else return search(r->rch, key);
}
bst::bst(int r[], int n)
{
	root = NULL;
	for (int i = 0; i < n; i++) {
		binode*s = new binode;
		s->data = r[i];
		s->lch = s->rch = NULL;
		insert(root, s);
	}
}
void bst::insert(binode*&r, binode*s)
{
	if (r == NULL)r = s;
	else if (s->data < r->data)insert(r->lch, s);
	else insert(r->rch, s);
}
bst::~bst()
{
	destroy(root);
}
void bst::destroy(binode*r)
{
	if (r != NULL) {
		destroy(r->lch);
		destroy(r->rch);
		delete r;
	}
}
int main()
{
	int n,a[100],key;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> key;
	bst t(a, n);
	t.search(t.root, key);
	cout << t.count;
}