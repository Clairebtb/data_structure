#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using std::vector;
using namespace std;
struct Node
{
	char data;
	 Node*lchild;
	 Node* rchild;
	//int parents;
};
class Tree
{
private:
	void create(Node *& R, char data[], int i, int n);//创建二叉树
	void Release(Node *r);                             //释放二叉树
public:
	Node * root;                      //根结点
	Tree(char data[], int length);   //构造函数
	~Tree();                           //析构函数
	int depth(Node*r);               //深度
	void preorder(Node*r);     //前序
	void inorder(Node*r);      //中序
	void levelorder(Node*r);   //层序
	void postorder(Node*r);    //后序
	void getpath(Node*r, char a, vector<int> &v);
	//void Tree::getpath(Node*r);      //指定结点到根的路径
	Node* find(Node*r,char a);
};
void  Tree::create(Node *& R, char data[], int i, int n)
{
	//if (R == root)R->parents = NULL;
	if (i <= n&&data[i - 1] != '0')
	{
		R = new Node;
		R->data = data[i - 1];
		create(R->lchild, data, 2 * i, n);
		//R->lchild->parents = R;
		create(R->rchild, data, 2 * i + 1, n);
		//R->rchild->parents = R;
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
int Tree::depth(Node*r)
{
	if (r == NULL)return 0;
	return depth(r->rchild) > depth(r->lchild) ? depth(r->rchild) + 1 : depth(r->lchild) + 1;

}
void Tree::preorder(Node*r)
{
	if (r != NULL) {
		if (r->data != '0') { cout << r->data; }
		preorder(r->lchild);
		preorder(r->rchild);

	}
}
void Tree::levelorder(Node*r)
{
	Node*queue[100];
	int f = 0, n = 0;
	if (r != NULL)queue[++n] = r;
	while (f != n) {
		Node*p = queue[++f];
		if (p->data != '0') { cout << p->data; }
		if (p->lchild != NULL)queue[++n] = p->lchild;
		if (p->rchild != NULL)queue[++n] = p->rchild;
	}
}
void Tree::inorder(Node*r)
{
	if (r != NULL) {
		inorder(r->lchild);
		cout << r->data;
		inorder(r->rchild);
	}
}
void Tree::postorder(Node*r)
{
	if (r != NULL) {
		postorder(r->lchild);
		postorder(r->rchild);
		cout << r->data;
	}
}
/*void Tree::getpath(Node*r)
{
	if (r == NULL) return;
	if (r!=NULL) {
		getpath(r->parents);
		cout << r->data;
	}

}*/
Node* Tree::find(Node*r,char a)
{
	Node*ret = NULL;
	if (r != NULL) {
		if (r->data == a)return r;
		//else if (r->lchild == NULL && r->rchild == NULL)return NULL;
		//else return find(r->lchild, a) == NULL ? find(r->rchild, a) : find(r->lchild, a);
		else {
			ret=find(r->lchild, a);
			if (ret == NULL) { ret = find(r->rchild, a); }
		}
	}
	else return NULL;
}
void Tree::getpath(Node*r, char a, vector<int> &v)
{
	if (r == NULL) {
		return;
	}
	v.push_back(r->data);
	if (r->data == a) {
		for (int i = 0; i < v.size(); i++) {
			putchar(v[i]);
		}
		cout << endl;
		return;
	}
	getpath(r->lchild, a, v);
	getpath(r->rchild, a, v);
	v.pop_back();
}
int main()
{
	char data[20];
	cin >> data;
	Tree t(data, strlen(data));
	t.preorder(t.root);
	cout << endl;
	t.postorder(t.root);
	cout << endl;
	t.levelorder(t.root);
	cout << endl;
	t.inorder(t.root);
	cout << endl;
	char a = 0;
	cin >> a;
	vector<int> v;
	t.getpath(t.root, a, v);
	int x=t.depth(t.find(t.root, a));
	cout << x<<endl;
	//t.getpath(t.find(t.root,a));
}
