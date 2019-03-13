/*题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

#include <cstdio>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;
        TreeNode* pre = NULL;
        convert_helper(pRootOfTree, pre);       
        TreeNode* res = pRootOfTree;
        while(res->left)
            res = res->left;
        return res;
    }

    void convert_helper(TreeNode* root, TreeNode*& pre) {

        if(root == NULL) {
            return;
        }

        convert_helper(root->left, pre);
        
        root->left = pre;
        if(pre) pre->right = root;
        pre = root;

        convert_helper(root->right, pre);
    }
};

int main() {
    return 0;
}
/*
思考：
二叉搜索树和双向链表有功能点
都是有两个指针、且都是左指针指向一个小的数，又指针指向一个大的数
pre 指针相当于left
next 指针相当于right
*/