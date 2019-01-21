/*http://codeup.cn/problem.php?cid=100000569&pid=1
问题 B: 习题6-5 数组元素逆置
时间限制: 1 Sec  内存限制: 12 MB
提交: 921  解决: 787
[提交][状态][讨论版][命题人:外部导入]
题目描述
将一个长度为10的整型数组中的值按逆序重新存放。

如：原来的顺序为1,2,3,4,5,6,7,8,9,0，要求改为0,9,8,7,6,5,4,3,2,1

输入
从键盘上输入以空格分隔的10个整数。

输出
按相反的顺序输出这10个数，每个数占一行。
样例输入
1 2 3 4 5 6 7 8 9 0
样例输出
0
9
8
7
6
5
4
3
2
1*/

#include <cstdio>
#define SIZE 10

int main(int argc, char const *argv[])
{
	int a[SIZE], temp;   
	
	// input 9 nums
	for (int i = 0; i < SIZE; ++i)
	{
		scanf("%d", &a[i]);
	}

	// swap
	if (SIZE > 1)
	{
		for (int i = 0; i < SIZE / 2; ++i)
		{
			temp = a[i];
			a[i] = a[SIZE-i-1];
			a[SIZE-i-1] = temp;
		}
	}

	// output
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}

// 总结，这个题目的思路很简单。此解法考虑到了如果只有一个元素的的数组情况。