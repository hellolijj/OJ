


#include <cstdio>
#include <vector>
#include <queue>

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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(pRoot);
        while(!q.empty()) {
            int length = q.size();  // 当前层的个数
            vector<int> temp;
            while(length--) {
                TreeNode *t = q.front();
                temp.push_back(t->val);
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
                q.pop();
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    return 0;
}

/*
对树的层次遍历的时候忘记队列的出列 
*/