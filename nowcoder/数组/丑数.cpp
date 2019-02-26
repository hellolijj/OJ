/*
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。


方法一：如下所示，
这种方法可以解决问题，但是运行的时间过长超过了题目要求的时间

*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool is_chou(int n) {
        if(n < 1) {
            return false;
        }
        while(n % 2 == 0) {
            n /= 2;
        }
        while(n % 3 == 0) {
            n /= 3;
        }
        while(n % 5 == 0) {
            n /= 5;
        }
        if(n == 1) {
            return true;
        } else {
            return false;
        }
    }


    int GetUglyNumber_Solution(int index) {
        if(index < 1) {
            return 0;
        }
        int chou_cnt = 0;    // 第i个丑数的值
        for(int i = 0; true; i++) {
            if(is_chou(i)) {
                chou_cnt++;
                if(chou_cnt == index) {
                    return i;
                }
            }
        }
    }

    int GetUglyNumber_Solution1(int index) {
        if(index < 7) {
            return index;
        }
        vector<int> res(index); 
        int p2 = 0, p3 = 0, p5 = 0; 
        res[0] = 1;
        for(int i = 1; i < index; i++) {
            res[i] = min(res[p2] * 2, min(res[p3] * 3, res[p5] * 5));
            if(res[i] == res[p2] * 2) p2++;
            if(res[i] == res[p3] * 3) p3++;
            if(res[i] == res[p5] * 5) p5++;
        }
        return res[index-1];
    }
};

int main() {
    class Solution solu;
    printf("%d\n", solu.GetUglyNumber_Solution(10));
    printf("%d\n", solu.GetUglyNumber_Solution1(10));
    return 0;
}