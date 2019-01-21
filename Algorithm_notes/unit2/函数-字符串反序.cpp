/*http://codeup.cn/problem.php?cid=100000570&pid=0
题目描述
写一个函数将一个字符串按反序存放。在主函数中输入一个字符串，通过调用该函数，得到该字符串按反序存放后的字符串，并输出。
输入
一行字符串。
输出
输入字符串反序存放后的字符串。单独占一行。
样例输入
abcd
样例输出
dcba*/
#include <cstdio>
#include <cstring>

void str_convert(char s[]) {

	char str[81];
	int i;
	for (i = 0; i < strlen(s); ++i)
	{
		str[i] = s[strlen(s)-1-i];
	}
	str[i] = '\0';
	strcpy(s, str);
}

int main(int argc, char const *argv[])
{
	char s[81];
	gets(s);
	str_convert(s);
	printf("%s\n", s);
	return 0;
}

// 此题目的逆转 采用借助第三方数组来实现的，也可以使用数组到的字符交换