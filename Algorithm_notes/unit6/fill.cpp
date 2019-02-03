#include <cstdio>
#include <algorithm>

int main(int argc, char const *argv[])
{
	int a[10];
	std::fill(a, a+10, 1);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}

	return 0;
}

// fill 可以填充 数组或者容器 vector