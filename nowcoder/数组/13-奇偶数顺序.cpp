/*题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

/*
这道题目除了使用队列做之外，也可以使用冒泡排序方法。

*/
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        queue<int> a;  // 奇数
        queue<int> b;  // 偶树
        for(int i = 0; i < array.size(); i++) {
            if(array[i] % 2 == 0) {
                b.push(array[i]);
            } else {
                a.push(array[i]);
            }
        }
        
        vector<int> res;
        while(!a.empty()) {
            res.push_back(a.front());
            a.pop();
        }
        while(!b.empty()) {
            res.push_back(b.front());
            b.pop();
        }
        
        // res => array
        for(int i = 0; i < res.size(); i++) {
            array[i] = res[i];
        }
        
    }
};

int main() {
    int a[7] = {1,2,3,4,5,6,7};
    class Solution solu;
    vector<int> v(7);
    for(int i = 0; i < v.size(); i++) {
        v[i] = a[i];
    }
    solu.reOrderArray(v);
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}

/