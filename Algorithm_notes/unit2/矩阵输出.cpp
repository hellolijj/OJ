/* http://codeup.cn/problem.php?cid=100000568&pid=5
输出以下4*5的矩阵

  1  2  3  4  5

  2  4  6  8 10

  3  6  9 12 15

  4  8 12 16 20

要求使用循环实现，注意每行输出5个数字，每个数字占3个字符的宽度，右对齐。

Matrix Length and Width

*/

#include <cstdio>

int main(int argc, char const *argv[])
{
	int length = 4, width = 5;
	for (int i = 1; i <= length; ++i)
	{
		for (int j = 1; j <= width; ++j)
		{
			printf("%3d", i * j);
		}
		printf("\n");
	}
	return 0;
}