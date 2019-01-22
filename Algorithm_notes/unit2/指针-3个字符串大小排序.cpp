/* http://codeup.cn/problem.php?cid=100000571&pid=3
题目描述
输入3个字符串，按从小到大的顺序输出。要求使用指针的方法进行处理。

输入
3行，每行一个用字符串。保证每个字符串的长度不超过20。

输出
按从小到大的顺序输出这3个字符串，每个字符串一行。
请注意行尾输出换行。*/

#include <cstdio>
#include <cstring>

void swap(char *s1, char *s2) {
	char temp[100];
	strcpy(temp, s1);
	strcpy(s1, s2);
	strcpy(s2, temp);
}

int main(int argc, char const *argv[])
{
	char a[100], b[100], c[100];
	scanf("%s%s%s", a, b, c);
	if (strcmp(a, b) > 0)
	{
		swap(a, b);
	}
	if (strcmp(b, c) > 0)
	{
		swap(b, c);
	}
	if (strcmp(a, b) > 0)
	{
		swap(a, b);
	}
	printf("%s\n%s\n%s\n", a, b, c);
	return 0;
}

/*总结：
1、此题目考察队字符串的输入操作
2、考察 通过指针交换字符串的用法*/