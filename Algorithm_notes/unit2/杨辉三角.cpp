// 杨辉三角.cpp
/*http://codeup.cn/problem.php?cid=100000569&pid=2
题目描述
按要求输入如下格式的杨辉三角

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1

最多输出10层

输入
输入只包含一个正整数n，表示将要输出的杨辉三角的层数。
输出
对应于该输入，请输出相应层数的杨辉三角，每一层的整数之间用一个空格隔开
样例输入
5
样例输出
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1*/

#include <cstdio>

#define MAX_SIZE 10

int main(int argc, char const *argv[])
{

	int a[MAX_SIZE][MAX_SIZE], n;
	scanf("%d", &n);
	if (n > MAX_SIZE)
	{
		printf("error: exceed on MAX_SIZE\n");
		return 0;
	}

	// @1 边界全部赋值1
	for (int i = 0; i < n; ++i)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}

	// @2 中间的数组 为上一层相邻的两个数之和
	for (int i = 2; i < n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	
	// output nums
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0) {
				printf("%d", a[i][j]);
			} else {
				printf(" %d", a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}

// 总结：杨辉三角，注意杨辉三角的求法。边界值赋值1，本行的数值与上一行的有关。