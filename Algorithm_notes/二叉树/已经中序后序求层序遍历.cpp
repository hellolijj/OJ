// 题意：已经二叉树的 后序遍历、中序遍历，求二叉树的层序遍历

#include <cstdio>

int n;      //节点个数
const int N = 31;
int post[N], pre[N], in[N];     //定义后序遍历、前序遍历、中序遍历

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
};

Node* create(int post_l, int post_r, int in_l, int in_r) {
	if (post_l > post_r)
	{
		return NULL;
	}

	Node* root = new Node;
	root->data = post[post_r];

	// 在中序序列中查找根节点k, k表示中序序列中根节点的下标
	int k;
	for (int k = in_l; k <= in_r; ++k)
	{
		if (in[k] == post[post_r])
		{
			break;
		}
	}

	int num_left = k - in_l;
	root->lchild = create(post_l, post_l+num_left-1, in_l, k-1);
	root->rchild = create(post_l+num_left, post_r-1, k+1, in_r);

	return root;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &in[i]);
	}
    printf("123o\n");
	Node *root = create(0, n-1, 0, n-1);
    printf("hello\n");
	return 0;
}

// 程序不能程序运行，是因为递归的层次太多吗？
// 果然是的，在本地电脑递归的层级不能太多。但是在线编译就可以通过。