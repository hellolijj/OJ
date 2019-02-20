/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

思路：使用递归是可以解决问题的
*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        TreeNode *p = pRoot;
        pRoot = getMirror(p);
    }
    
    TreeNode* getMirror(TreeNode *pRoot){
        if(pRoot == NULL) {
            return NULL;
        }
        
        TreeNode* new_right = getMirror(pRoot->left);
        TreeNode* new_left = getMirror(pRoot->right);

        pRoot->right = new_right;
        pRoot->left = new_left;
        return pRoot;
    }
};