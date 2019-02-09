// 题意：已经二叉树的 后序遍历、中序遍历，求二叉树的层序遍历

#include <cstdio>
#include <queue>

using namespace std;

int n;      //节点个数
const int N = 31;
int post[N], pre[N], in[N];     //定义后序遍历、前序遍历、中序遍历

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
};

Node* create_by_post_and_in(int post_l, int post_r, int in_l, int in_r) {
	if (post_l > post_r)
	{
		return NULL;
	}

	Node* root = new Node;
	root->data = post[post_r];

	// 在中序序列中查找根节点k, k表示中序序列中根节点的下标
	int k;
	for (k = in_l; k <= in_r; k++)
	{
		if (in[k] == post[post_r])
		{
			break;
		}
	}

	int num_left = k - in_l;
	root->lchild = create_by_post_and_in(post_l, post_l+num_left-1, in_l, k-1);
	root->rchild = create_by_post_and_in(post_l+num_left, post_r-1, k+1, in_r);

	return root;
}

Node* create_by_pre_and_in(int pre_l, int pre_r, int in_l, int in_r) {
	if (pre_l > pre_r)
	{
		return NULL;
	}
	Node* root = new Node;
	root->data = pre[pre_l];

	int k;
	for (k = in_l; k <= in_r; k++)
	{
		if (in[k] == pre[pre_l])
		{
			break;
		}
	}

	int num_left = k - in_l;
	root->lchild = create_by_pre_and_in(pre_l+1, pre_l+num_left, in_l, k-1);
	root->rchild = create_by_pre_and_in(pre_l+num_left+1, pre_r, k+1, in_r);
	return root;
}

// 层次遍历 bfs
void BFS(Node* root) {
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

// 前序遍历
void preorder(Node* root) {
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	if (root->lchild != NULL)
	{
		preorder(root->lchild);	
	}
	if (root->rchild != NULL)
	{
		preorder(root->rchild);	
	}
	
}

// 中序遍历
void inorder(Node* root) {
	if (root == NULL)
	{
		return;
	}
	if (root->lchild != NULL)
	{
		inorder(root->lchild);	
	}
	printf("%d ", root->data);
	if (root->rchild != NULL)
	{
		inorder(root->rchild);	
	}
	
}

// 后序遍历
void postorder(Node* root) {
	if (root == NULL)
	{
		return;
	}
	if (root->lchild != NULL)
	{
		postorder(root->lchild);	
	}
	if (root->rchild != NULL)
	{
		postorder(root->rchild);	
	}
	printf("%d ", root->data);
	
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	// for (int i = 0; i < n; i++)
	// {
	// 	scanf("%d", &post[i]);
	// }
	// for (int i = 0; i < n; i++)
	// {
	// 	scanf("%d", &in[i]);
	// }
	// Node *root = create_by_post_and_in(0, n-1, 0, n-1);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	Node *root = create_by_pre_and_in(0, n-1, 0, n-1);

	BFS(root);
	preorder(root);
	printf("\n");

	inorder(root);
	printf("\n");

	postorder(root);
	printf("\n");
    
	return 0;
}

// 程序不能程序运行，是因为递归的层次太多吗？
// 果然是的，在本地电脑递归的层级不能太多。但是在线编译就可以通过。

// todo 如何通过层次遍历和中序遍历创建一个二叉树