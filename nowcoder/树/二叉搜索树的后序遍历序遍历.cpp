/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

链接：https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd
来源：牛客网

思路：
已知条件：后序序列最后一个值为root；二叉搜索树左子树值都比root小，右子树值都比root大。
1、确定root；
2、遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
3、遍历右子树，若发现有小于root的值，则直接返回false；
4、分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）。
*/


/*
测试用例： {1,2,3,4,5}, {1,2}, {1},{0}
*/

#include <cstdio>
#include <vector>

using namespace std;


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if(length == 0 || length == 1) {
            return true;
        }
        

        int root = sequence[length-1];
        int k=0;
        while(k < length && sequence[k] < root) {
            k++;
        }
        
        // 此时sequence[k] 是第一个 >= root的值， 随后k+1 ~ length-2 值都 > k则返回true
        while(k < length-1) {
            if(sequence[k] >= root) {
                k++;
                continue;
            }
            return false;
        }
        
        vector<int>left(sequence.begin(), sequence.begin()+k-1);
        vector<int>right(sequence.begin()+k, sequence.begin()+length-1);

        return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
    }
};

int main() {
    int a[7] = {5,7,6,8,11,10,8};
    vector<int> p;
    for(int i = 0; i < 7; i++) {
        p.push_back(a[i]);
    }

    class Solution solu;
    if(solu.VerifySquenceOfBST(p)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}