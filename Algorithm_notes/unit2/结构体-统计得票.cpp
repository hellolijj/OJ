/*http://codeup.cn/problem.php?cid=100000572&pid=0
题目描述
完成一个对候选人得票的统计程序。假设有3个候选人，名字分别为Li，Zhang和Fun。使用结构体存储每一个候选人的名字和得票数。记录每一张选票的得票人名，输出每个候选人最终的得票数。结构体可以定义成如下的格式：
struct person {
    char name[20];
    int count;
}leader[3] = {“Li”, 0, “Zhang”, 0, “Fun”, 0};

输入
第一行有一个整数n，表示以下有n张选票信息将会输入。保证n不大于100。
以后的n行中，每一行包含一个人名，为选票的得票人。保证每一个人名都是Li，Zhang和Fun中的某一个。

输出
有三行，分别为Li，Zhang和Fun每人的得票数。格式为首先输出人名，其后输出一个冒号，最后输出候选人的得票数。
请注意行尾输出换行。

样例输入
10
Li
Li
Fun
Zhang
Zhang
Fun
Li
Fun
Zhang
Li
样例输出
Li:4
Zhang:3
Fun:3
*/


#include <cstdio>
#include <cstring>

struct person
{
	char name[20];
	int count;
}leader[3]={"Li", 0, "Zhang", 0, "Fun", 0};

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		char input_name[20];
		scanf("%s", input_name);
		if (strcmp(leader[0].name, input_name) == 0)
		{
			leader[0].count ++;
		}

		if (strcmp(leader[1].name, input_name) == 0)
		{
			leader[1].count ++;
		}

		if (strcmp(leader[2].name, input_name) == 0)
		{
			leader[2].count ++;
		}
	}
	printf("%s:%d\n", leader[0].name, leader[0].count);
	printf("%s:%d\n", leader[1].name, leader[1].count);
	printf("%s:%d\n", leader[2].name, leader[2].count);

	return 0;
}

总结：
1、此题目考查了结构体的简单操作，输入，输出。与平常变量操作无异。
2、值得注意的是这个题目关于结构体的初始化。