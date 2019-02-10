// 构建一个平衡二叉树，然后输出平衡二叉树根节点的值

#include <cstdio>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	int height;
	Node* lchild;
	Node* rchild;
};

Node* root;

// 获取avl的高度
int get_height(Node *root) {
	if (root == NULL)
	{
		return 0;
	}
	return root->height;
}

// 获取平衡二叉树的平衡因子
int get_balance_factor(Node* root) {
	return get_height(root->lchild) - get_height(root->rchild);
}

// 更新节点root的高度
int update_height(Node* root) {
	// if (get_height(root->lchild) > get_height(root->rchild))
	// {
	// 	return get_height(root->lchild) + 1;
	// } else {
	// 	return get_height(root->rchild) + 1;
	// }
	
	return max(get_height(root->lchild), get_height(root->rchild)) + 1;
}

// 左转
void L(Node* &root) {
	Node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	update_height(root);
	update_height(temp);
	root = temp;
};

// 右转
void R(Node* &root) {
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	update_height(root);
	update_height(temp);
	root = temp;
}

// 插入权重为 v 的节点

void insert(Node* &root, int data) {
	if (root == NULL)
	{
		root = new Node;
		root->data = data;
		root->height = 1;
		root->lchild = root->rchild = NULL;
		return;
	}



	if (data < root->data) {
		insert(root->lchild, data);
		update_height(root);

		if (get_balance_factor(root) == 2)
		{
			if (get_balance_factor(root->lchild) == 1) {  // LL 型
				R(root);
			} else if (get_balance_factor(root->rchild) == -1) {  // LR 型
				L(root->lchild);
				R(root);
			}
		} 

	} else {
		insert(root->rchild, data);
		update_height(root);

		if (get_balance_factor(root) == -2)
		{
			if (get_balance_factor(root->rchild) == -1)
			{
				L(root);
			} else if (get_balance_factor(root->lchild) == 1)
			{
				R(root->rchild);
				L(root);
			}
		}

	}
}

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
	int n;
	scanf("%d", &n);
	// Node* root = NULL;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		insert(root, temp);
	}

	postorder(root);
	printf("\n");
	printf("%d %d\n", root->data, root->height);
	
	return 0;
}



// 平衡二叉树的难点，相对于二叉排序数来说，对于平衡这个要求。
// 因此需要对构建平衡二叉树时，四种情况的一种理解和对应的操作