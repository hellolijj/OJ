/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）

思路：
那么如何才算 a 是 b的子树呢？
            8
    	   /  \
    	  6   10
    	 / \  / \
    	5   7 9  11

在这棵树中
          6   
    	 / \  
    	5   7
就是子树。 单独一个5也是子树。单独一个6也算是子树

思路整理：
参照剑指offer
1、首先设置标志位result = false，因为一旦匹配成功result就设为true，
剩下的代码不会执行，如果匹配不成功，默认返回false
2、递归思想，如果根节点相同则递归调用DoesTree1HaveTree2（），
如果根节点不相同，则判断tree1的左子树和tree2是否相同，
再判断右子树和tree2是否相同
3、注意null的条件，HasSubTree中，如果两棵树都不为空才进行判断，
DoesTree1HasTree2中，如果Tree2为空，则说明第二棵树遍历完了，即匹配成功，
tree1为空有两种情况（1）如果tree1为空&&tree2不为空说明不匹配，
（2）如果tree1为空，tree2为空，说明匹配。

代码整理

less is more
*/

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL || pRoot1 == NULL) {
            return false;
        }

        // 这一个return 不太好理解 less is more
        return DoesTree1ContainTree2(pRootA, pRootB) ||
            HasSubtree(pRootA->left, pRootB) ||
            HasSubtree(pRootA->right, pRootB);
        
        /*if(pRoot1->val == pRoot2->val) {
            return DoesTree1ContainTree2(pRoot1, pRoot2);
        } 
        if(pRoot1->left != NULL) {
            return HasSubtree(pRoot1->left, pRoot2);
        }
        if(pRoot1->right != NULL) {
            return HasSubtree(pRoot1->right, pRoot2);
        }*/
    }

    // contain means 节点值相同 proot2有的proot1都有，也称pRoot2是pRoot1的子树
    bool DoesTree1ContainTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2 == NULL) {
            return true;
        }
        if(pRoot1 == NULL) {
            return false;
        }

        if (pRoot1->val != pRoot2->val) {
            return false;
        }

        return DoesTree1ContainTree2(pRoot1->left, pRoot2->left) && DoesTree1ContainTree2(pRoot1->right, pRoot2->right);
    }
};