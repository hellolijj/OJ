/*题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

思路：
模拟栈的压入压出过程
// 建立一个栈
stack<int> s;
for(i = 0, j = 0; i < pushV.size(); i++) {
    s.push(pushV[i]);
    while(j < popV.size() && s.top() == popV[j]) {
        s.pop();
        j++;
    }
}
return s.empty();
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        if(pushV.size() != popV.size()) {
            return false;
        }
        // 都只有一个序列且相等
        int i, j;
        stack<int> s;
        for(i = 0, j = 0; i < pushV.size(); i++) {
            s.push(pushV[i]);
            while(j < popV.size() && s.top() == popV[j]) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};