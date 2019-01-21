/* http://codeup.cn/problem.php?cid=100000567&pid=2

三个数从小到大排序

从键盘输入3个实数a, b, c，通过比较交换，将最小值存储在变量a中，
最大值存储在变量c中，中间值存储在变量b中，并按照从小到大的顺序输出这三个数a, b, c。

末尾输出换行。

*/

#include <cstdio>

void swap(double *num1, double *num2) {
	double temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main(int argc, char const *argv[])
{
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);

	if (a > b) {
		swap(&a, &b);
	}

	if (b > c) {
		swap(&b, &c);
	}

	if (a > b) {
		swap(&a, &b);
	}

	printf("%.2f %.2f %.2f\n", a, b, c);
	return 0;
}
/*
总结，
1、此题目注意使用指针交换的用法
2、注意实参形参交换的概念
3、⚠️3个数比大小容易掉入一个圈套：ab对比，bc对比，然后再ac对比这样的组合场景。
这样其实是不对的。先，ab对比，bc，对比确定最大数C，然后再ab对比确定较大数b
*/