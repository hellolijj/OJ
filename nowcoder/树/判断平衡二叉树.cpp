/*题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。


思路二
这种做法有很明显的问题，在判断上层结点的时候，会多次重复遍历下层结点，
增加了不必要的开销。如果改为从下往上遍历，如果子树是平衡二叉树，则返回子树的高度；
如果发现子树不是平衡二叉树，则直接停止遍历，这样至多只对每个结点访问一次。
*/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) {
            return true;
        }

        // 这个的逻辑比较好理解一点
        int leftDepth = getDepth(pRoot -> left);
        int rightDepth = getDepth(pRoot -> right);
        if(abs(leftDepth - rightDepth) >= 2)
            return false;
        else
            return IsBalanced_Solution(pRoot -> left) && IsBalanced_Solution(pRoot -> right);


        // return abs(get_max_depth(pRoot->left)-get_max_depth(pRoot->right)) <= 1 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
        /*if(abs(get_max_depth(pRoot->left)-get_max_depth(pRoot->right)) > 2) {
            return false;
        }
        bool left_balanch_tree = IsBalanced_Solution(pRoot->left);
        bool right_balanch_tree = IsBalanced_Solution(pRoot->right);
        if(left_balanch_tree && right_balanch_tree) {
            return true;
        } else {
            return false;
        }*/
    }

    int get_max_depth(TreeNode* pRoot) {
        if(pRoot == NULL) {
            return 0;
        }
        return max(get_max_depth(pRoot->left), get_max_depth(pRoot->right)) + 1;
    }



    // 思路二，在getDepth中，如果发现不是平衡二叉树，则返回-1。 调用函数发现-1 理解停止
    public boolean IsBalanced_Solution(TreeNode root) {
        return getDepth(root) != -1;
    }
     
    private int getDepth(TreeNode root) {
        if (root == null) return 0;
        int left = getDepth(root.left);
        if (left == -1) return -1;
        int right = getDepth(root.right);
        if (right == -1) return -1;
        return Math.abs(left - right) > 1 ? -1 : 1 + Math.max(left, right);
    }
};