/*http://codeup.cn/problem.php?cid=100000569&pid=7
题目描述
从键盘上输入10个整数，用冒泡法对这10个数进行排序（由小到大）。
输入
以空格分隔的10个整数
输出
依次输出排好序的10个整数，每个数占一行。
样例输入
1 3 5 7 9 2 4 6 8 0
*/
#include <cstdio>
#define SIZE 10

int main(int argc, char const *argv[])
{
	int a[SIZE], temp;   
	
	for (int i = 0; i < SIZE; ++i)
	{
		scanf("%d", &a[i]);
	}

	// 排序
	for (int i = 0; i < SIZE-1; ++i)
	{
		for (int j = 0; j < SIZE - i - 1 ; ++j)
		{
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	// output
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}