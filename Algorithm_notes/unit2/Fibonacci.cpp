/*输入一个正整数n，求Fibonacci数列的第n个数。
Fibonacci数列的特点：第1,2个数为1,1。
从第3个数开始，概述是前面两个数之和。*/

# include <cstdio>
int fibonacci(int n) {
	if (n <= 0 || n > 50) {
		printf("error: n 范围: 1~50\n");
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	int a = 1, b = 1;
	int i, c = 1;                     // c 初始值，定义什么都可以
	for (int i = 3; i <= n; ++i)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fibonacci(n));
	return 0;
}

/*总结：
1、求 Fibonacci 数列 先在草稿纸上画几个值，然后手动循环便历，有窗口在滑动的感觉
2、此处是用循环做的，其实还可以尝试使用递归做法。*/