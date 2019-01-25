// http://codeup.cn/problem.php?cid=100000572&pid=1

#include <cstdio>

struct student
{
	int num;
	char name[20];
	char sex;
	int age;
};

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	if (n <= 0 || n > 20)
	{
		printf("error\n");
		return 0;
	}
	student stu[20];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %s %c %d", &stu[i].num, stu[i].name, &stu[i].sex, &stu[i].age);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d %s %c %d\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].age);
	}
	return 0;
}

// 总结：这个程序运行不通，不知原因何在？