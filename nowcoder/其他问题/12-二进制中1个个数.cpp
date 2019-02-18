#include<cstdio>
/*
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
class Solution {
public:
     int  NumberOf1(int n) {

         int res = 0;
         while(n != 0) {
            if(n % 2 == 1) {
                res++;
            }
            n = n / 2;
         }
         return res;
         
     }
};

int main() {
    class Solution solu;
    printf("%d\n", solu.NumberOf1(3));
    return 0;
}

/*
这个题目需要搞清楚 负数 的补码怎么表示？
原码
反码
补码
又怎么求？怎么补充？

原码：就是 |n|的二进制。正数是它本身，负数就是它的相反数（正数）的编码。
反码：对所有的位数取反。 1->0  0->1就是反码
补码：就是对反码进行取1就是补码。

负数的表示是通过补码表示的。
例如：-5
源码：101（00000101）
反码：11111010
补码： 11111011
所以 -5的编码表示为 11111011
*/