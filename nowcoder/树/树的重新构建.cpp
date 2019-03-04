/*题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和
中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

#include <vector>

using namespace std;
/**
 * Definition for binary tree
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {

        if(vin.size() == 0) {
            return NULL;
        }

        TreeNode* root = new TreeNode;
        root->val = pre[0];
        int k;
        for(k = 0; k < vin.size(); k++){
            if(vin[k] == root->val){
                break;
            }
        }

        vector<int> pre_left(pre.begin()+1, pre.begin()+k);
        vector<int> pre_right(pre.begin()+k+1, pre.end());
        vector<int> vin_left(vin.begin(), vin.begin()+k-1);
        vector<int> vin_right(vin.begin()+k+1, vin.end());
        vector<int> pre_left, pre_right, vin_left, vin_right;
        for(int i = 0; i < k; i++) {
            pre_left.push_back(pre[i+1]);
            vin_left.push_back(vin[i]);
        }
        for(int i = k+1; i < vin.size(); i++) {
            pre_right.push_back(pre[i]);
            vin_right.push_back(vin[i]);
        }
        root->left = reConstructBinaryTree(pre_left, vin_left);
        root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
    }
};

int main() {
    return 0;
}

/*
不同点：
在本地环境中，构造一个结构体
TreeNode* root = new TreeNode;
而在牛客网中，
TreeNode* root = new TreeNode(pre[0]);
注意⚠️
本题易错点
递归调用的出口
if(vin.size() == 0) return NULL

还有最后返回 root
*/

