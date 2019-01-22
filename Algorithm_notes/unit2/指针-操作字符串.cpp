/*http://codeup.cn/problem.php?cid=100000571&pid=2
题目描述
给定字符串定义char *a = “I love China!”，读入整数n，输出在进行了a = a + n这个赋值操作以后字符指针a对应的字符串。

输入
一个整数n，保证0<=n<13.

输出
输出进行了题目描述中赋值操作之后a对应的字符串。
请注意行尾输出换行。

样例输入
7
样例输出
China!*/
#include <cstdio>

int main(int argc, char const *argv[])
{
	char *a = "I love China!";   // 这里使用const 是规范的写法
	int n;
	scanf("%d", &n);
	if (n < 0 || n >= 13)
	{
		printf("error: n 反问 [0, 13)\n");
		return -1;
	}

	printf("%s\n", a+n);
	return 0;
}

/*总结： 在定义 char *a 的时候，编译报了一个warning

warning: conversion from
string literal to 'char *' is deprecated
[-Wc++11-compat-deprecated-writable-strings]
schar *a = "I love China!"; 

需要通过 const char *a 来解决，因为是 const, 所以不能修改。这样写比较规范*/