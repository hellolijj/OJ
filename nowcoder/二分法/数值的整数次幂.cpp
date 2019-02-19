#include<cstdio>

using namespace std;

/*思路
方法一：二分法的幂函数运算 时间复杂度o(lgn) 如果累计*的话 时间复杂度o(n)
n 位偶数 
a ^ n = a ^ (n/2) * a ^ (n/2);
n为基数 
a ^ n = a ^ ((n-1)/2)) * a ^ ((n-1)/2)) * a;

递归的出口是 
if(n==1) return 0

*/
class Solution {
public:
    double Power(double base, int exponent) {

        if(exponent < 0) {
            return 1 / Power(base, 0 - exponent);
        }

        if(exponent == 0) {
            return 1;
        }

        if(exponent % 2 == 0) {
            double temp = Power(base, exponent/2);
            return temp * temp;
        } else {
            double temp = Power(base, (exponent-1)/2);
            return temp * temp * base;
        }

        return base;
    }
};

int main() {
    class Solution solu;
    printf("%.2f\n", solu.Power(1.2, -1));
    return 0;
}

// 错误原因，未考虑n为负数的情况