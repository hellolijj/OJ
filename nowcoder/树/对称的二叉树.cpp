/*题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    
    void get_left_seq(TreeNode* pRoot, vector<int> &left) {
        if(pRoot == NULL) {
            return;
        }
        left.push_back(pRoot->val);
        get_left_seq(pRoot->left, left);
        get_left_seq(pRoot->right, left);
    }
    
    void get_right_seq(TreeNode* pRoot, vector<int> &right) {
        if(pRoot == NULL) {
            return ;
        }
        right.push_back(pRoot->val);
        get_right_seq(pRoot->right, right);
        get_right_seq(pRoot->left, right);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        vector<int> left;
        vector<int> right;
        get_left_seq(pRoot, left);
        get_right_seq(pRoot, right);
        
        return left == right;
    }

    bool isSymmetrical1(TreeNode* pRoot)
    {
        if(pRoot == NULL) {
            return true;
        };

        return isDuichen1(pRoot->left, pRoot->right);
    }

    bool isDuichen1(TreeNode *left,TreeNode *right) {
        if(left == NULL && right == NULL) {
            return true;
        }
        if(left == NULL ^ right == NULL) {
            return false;
        }
        // 接下来两个都不为空
        if(left->val != right->val) {
            return false;
        }

        return isDuichen1(left->left, right->right) && isDuichen1(right->left, left->right);

    }
};

/*
注意: 
我本来想通过 先序遍历，通过遍历它的对称镜像的遍历得到的序列
两个序列进行对比即可得到结果。 这种方法是不对的，对于重复的数组，不通过测试用例


*/