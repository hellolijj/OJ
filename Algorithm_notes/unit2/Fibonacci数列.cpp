/*http://codeup.cn/problem.php?cid=100000569&pid=6
题目描述
Fibonacci数列的特点：第1,2个数为1,1。从第3个数开始，概述是前面两个数之和。即： 

要求输出Fibonacci数列的前20个数。

输入
无
输出
Fibonacci数列的前20个数，每个数占一行。
样例输入
无
样例输出
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765*/

# include <cstdio>
# define MAX_SIZE 50
int main(int argc, char const *argv[])
{
	int n = 20, a[MAX_SIZE];             // 这里n=20，主要是考虑到练习的时候n的值可以手动输入
	if (n <= 0 || n > MAX_SIZE) {
		printf("error: n 范围: 1~50\n");
		return 0;
	}

	a[0] = 1; a[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		a[i] = a[i-1] + a[i-2];
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}