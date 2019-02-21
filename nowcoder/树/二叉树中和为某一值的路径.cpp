/*题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)

*/
#include <cstdio>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// todo 排序
class Solution {
public:

    /* 初始版本
    vector<vector<int> > res;

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        
        if(root == NULL) {
            return res;
        }

        vector<int> current_path;
        find(root, current_path, expectNumber, 0);
        return res;

    }
    
    void find(TreeNode* root, vector<int> current_path, int expect_number, int current_sum) {

        if(root == NULL) {
            return;
        }

        current_path.push_back(root->val);

        // 满足路径要求
        if (root->left == NULL && root->right == NULL && current_sum + root->val == expect_number) {
            res.push_back(current_path);
            
        } else {
            // 否则，遍历两边的树
            if(root->left != NULL){
                find(root->left, current_path, expect_number, current_sum+root->val);
            }
            if(root->right != NULL){
                find(root->right, current_path, expect_number, current_sum+root->val);
            }
        }

        
        // 出列
        current_path.pop_back();
    }

    */

    // 简介版本
    vector<vector<int> > res;
    vector<int> temp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL) {
            return res;
        }
        temp.push_back(root->val);
        int current_sum = 0;
        for(int i = 0; i < temp.size(); i++) {
            current_sum += temp[i];
        }
        if(root->left == NULL && root->right == NULL && current_sum == expectNumber) {
            res.push_back(temp);
        } else {
            if(root->left != NULL) {
                FindPath(root->left, expectNumber);
            }
            if(root->right != NULL) {
                FindPath(root->right, expectNumber);
            }
        } 
        temp.pop_back();
        return res;
    }
};

int main() {
    return 0;
}