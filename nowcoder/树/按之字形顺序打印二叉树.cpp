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

        bool flag = true;   // 用于标记奇偶

        while(!q.empty()) {
            int length = q.size();
            vector<int> temp;
            while(length--) {
                TreeNode* t = q.front();
                temp.push_back(t->val);
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
                q.pop();
            }
            if(flag == false) {
                reverse(temp.rbegin(), temp.rend());
            }
            res.push_back(temp);
            flag = !flag;
        }
        return res;
    }
    
};

int main() {
    return 0;
}

/* 注意：
如果考虑到奇偶行的 reverse 太过消耗时间的话，
也可以使用 

if(t->right != NULL) q.push(t->right); 
if(t->left != NULL) q.push(t->left);
                
来实现

也可以对queue 进行倒序输出


*/