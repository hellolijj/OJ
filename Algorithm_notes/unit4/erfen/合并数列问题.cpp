#include <cstdio>

int main(int argc, char const *argv[])
{
	int a[3] = {1, 2, 6};
	int b[6] = {3, 4, 5, 6, 7, 12};
	int c[9];

	int i = 0, j = 0, k = 0;
	while(i < 3 && j < 6) {
		if (a[i] <= b[j]) {
			c[k++] = a[i++];
		} else {
			c[k++] = b[j++];
		}
	}

	// 将尾数添加❤新的数组
	while(i < 3) {
		c[k++] = a[i++];
	}
	while(j < 6) {
		c[k++] = b[j++];
	}

	for (int i = 0; i < 9; ++i)
	{
		printf("%d ", c[i]);
	}
	printf("\n");

	return 0;
}