/*
第三题：等式变换
输入一个正整数X，在下面的等式左边的数字之间添加+号或者-号，使得等式成立。
1 2 3 4 5 6 7 8 9 = X
比如：
12-34+5-67+89 = 5
1+23+4-5+6-7-8-9 = 5
请编写程序，统计满足输入整数的所有整数个数。
输入： 正整数，等式右边的数字
输出： 使该等式成立的个数
样例输入：5
样例输出：21
*/

#include <cstdio>

//动态规划
//动态方程（有点难理解）：当前种类=符号位加号+符号为减号+没有符号的种类
//dp(before,des,n,ex)= dp(before - 1, before, res + des,1) + dp(before - 1, before, res - des,1) + dp(before - 1, before*pow(10, ex)+des, res,ex+1);
// before: 需要判定的符号前面的数字的个数，初始为8
// des: 需要判定的符号后面的数字，初始为9
// n:方程右边的结果
// ex:阶乘数，因为符号有三种可能，加号，减号，或者没有，如果没有，那么ex就用于计算当前值
#include<iostream>
#include<cmath>
using namespace std;
int dp(int before, int des, int res,int ex) {
	if (before == 0) {
		if (des == res) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return dp(before - 1, before, res + des,1) + dp(before - 1, before, res - des,1) + dp(before - 1, before*pow(10, ex)+des, res,ex+1);
	}
}
int main(){
	int n; cin >> n;
	cout << dp(8,9,n,1);

}