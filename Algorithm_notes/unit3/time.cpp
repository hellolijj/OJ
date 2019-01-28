#include <cstdio>

int mouth[13][2] = {
	{0, 0},
	{31, 31},
	{28, 29},
	{31, 31},
	{30, 30},
	{31, 31},
	{30, 30},
	{31, 31},
	{31, 31},
	{30, 30},
	{31, 31},
	{30, 30},
	{31, 31}
};

bool isLeap(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main(int argc, char const *argv[])
{
	int time1, year1, mouth1, day1;
	int time2, year2, mouth2, day2;
	while(scanf("%d %d", &time1, &time2) != EOF) {
		if (time1 > time2) {
			int temp = time1;
			time2 = time1;
			time1 = time2;
		}
		
		year1 = time1 / 10000, mouth1 = (time1 % 10000) / 100, day1 = time1 % 1000000;
		year2 = time2 / 10000, mouth2 = (time2 % 10000) / 100, day2 = time2 % 1000000;
		int ans = 1;       // 记录结果

		// 即 !(year1 == year2 && mouth1 == mouth2 && day1 == day2)
		while(year1 < year2 || mouth1 < mouth2 || day1 < day2) {
			day1 ++;
			if(day1 == mouth[mouth1][isLeap(year1)]) {
				day1 = 1;
				mouth1 ++;
			}

			if(mouth1 == 13) {
				mouth1 = 1;
				year1++;
			}

			ans ++;
		}

		printf("%d\n", ans);

	}

	return 0;
}

// 总结：输入两个日期，一个小日期，一个大日期。
// 通过小日期不断相加知道两个日期相等位置。来计算两个日期之差。
// 1、年月日格式的确定： year = time / 10000
// 2、润年及韵年2月的确定： 通过数字的方式来确定的。