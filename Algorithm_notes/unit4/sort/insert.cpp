#include <cstdio>

int main(int argc, char const *argv[])
{
	/* code */
	int a[10];
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}

	// sort
	for (int i = 1; i < 10; ++i)    // 进行i-1次排序
	{
		int temp = a[i], j = i;     // j从i开始往前枚举
		while(j > 0 && temp < a[j-1]) {       // j > 0 防止j--变成了负数
			a[j] = a[j-1];
			j--;
		}
		a[j] = temp;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
}

// 总结：在移动的过程中注意防止越界