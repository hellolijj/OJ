// 通过给定的一个序列创建一个二叉查找树。

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// origin 输入的序列 pre 前序遍历数列 pre_m 镜像树遍历数列
// post 后续遍历序列  post_m 镜像树后序遍历
vector<int> origin, pre, pre_m, post, post_m;

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
};

void layer_order(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node * top = q.front();
		q.pop();
		printf("%d ", top->data);
		if (top->lchild != NULL)
		{
			q.push(top->lchild);
		}
		if (top->rchild != NULL)
		{
			q.push(top->rchild);
		}
	}
	printf("\n");
}

// 将一个元素插入到二叉排序树中
void insert(Node* &root, int num) {

	if (root == NULL) {
		root = new Node;
		root->data = num;
		root->lchild = root->rchild = NULL;
		return;
	} else if (num >= root->data) {
		insert(root->rchild, num);
	} else {
		insert(root->lchild, num);
	}

}

// 将二叉排序树前序遍历 放入 pre 动态数组里
void pre_order(Node* root, vector<int> &v) {

	if (root == NULL)
	{
		return;
	}

	v.push_back(root->data);
	pre_order(root->lchild, v);
	pre_order(root->rchild, v);
}

void pre_m_order(Node* root, vector<int> &v) {

	if (root == NULL)
	{
		return;
	}

	v.push_back(root->data);
	pre_m_order(root->rchild, v);
	pre_m_order(root->lchild, v);
}

void post_order(Node* root, vector<int> &v) {

	if (root == NULL)
	{
		return;
	}

	v.push_back(root->data);
	post_order(root->lchild, v);
	post_order(root->rchild, v);
}

void post_m_order(Node* root, vector<int> &v) {

	if (root == NULL)
	{
		return;
	}

	v.push_back(root->data);
	post_m_order(root->rchild, v);
	post_m_order(root->lchild, v);
}

int main(int argc, char const *argv[])
{
	int n;
	Node* root;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		origin.push_back(temp);
		insert(root, temp);
	}

	pre_order(root, pre);
	pre_m_order(root, pre_m);
	post_order(root, post);
	post_m_order(root, post_m);
	
	if (origin == pre) {

		printf("YES\n");
		for (int i = 0; i < post.size(); ++i)
		{
			printf("%d ", post[i]);
		}

	} else if(origin == pre_m) {
		
		printf("YES\n");
		for (int i = 0; i < post_m.size(); ++i)
		{
			printf("%d ", post_m[i]);
		}

	} else {
		
		printf("NO\n");
		
	}
	
	
	return 0;
}