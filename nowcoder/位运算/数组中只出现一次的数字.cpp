/*题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。
请写程序找出这两个只出现一次的数字。

思路：
我们已经知道了一个数组中，除了一个数字外，其他数字出现了偶数次的数字。
在这个题目中，我们需要对数组进行划分为2个只出现一次的数组
*/
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        
        /*
        testcase: {1, 1,2,3, 2, 4}, {}, {1,2};
        一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字·
        */
        if(data.empty() || data.size() < 2) {
            return;
        }
        // 进行匹配
        int flag = 0;
        for(int i = 0; i < data.size(); i++) {
            flag = flag ^ data[i];
        }
        int flag_first_1 = get_first_1(flag);
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < data.size(); i++) {
            if(is_last_n1(data[i], flag_first_1)) {
                v1.push_back(data[i]);
            } else {
                v2.push_back(data[i]);
            }
        }

        *num1 = 0;
        *num2 = 0;
        for(int i = 0; i < v1.size(); i++) {
            *num1 = *num1 ^ v1[i];
        }
        for(int i = 0; i < v2.size(); i++) {
            *num2 = *num2 ^ v2[i];
        }

    }

    // 从右边树第一个值为1的位数 如  1000101000 返回 4
    unsigned int get_first_1(int n) {
        unsigned int res = 0;
        while((n&1) == 0 && res < 8 * sizeof(int)) {
            res ++;
            n = n >> 1;
        }
        return res;
    }

    // 判断一个数字n 从右数，第m位 是不是1
    bool is_last_n1(int n, unsigned int m) {
        n = n >> m;
        return n & 1;
    }
};

int main() {
    return 0;
}