#include <cstdio>
#include <vector>

using namespace std;

/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
思路
本质上还是一个fibo数列问题
f(n) = f(n-1) + f(n-2)
*/

class Solution {
private:
	int a[101];
public:
    int jumpFloor(int number) {
        a[1] = 1;
        a[2] = 2;

        for(int i = 3; i <= number; i++) {
        	a[i] = a[i-1] + a[i-2];
        }
        return a[number];

    }
};

int main() {
	class Solution solu;
	for(int i = 0; i <= 39; i++) {
		printf("%d\n", solu.jumpFloor(i));
	}
	
}