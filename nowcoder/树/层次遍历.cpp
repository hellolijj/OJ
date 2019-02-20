// 层次遍历

#include <cstdio>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        
        queue<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* top = s.front();
            res.push_back(top->val);
            s.pop();
            if(top->left != NULL) {
                s.push(top->left);
            }
            if(top->right != NULL) {
                s.push(top->right);
            }
        }
        return res;
    }
};