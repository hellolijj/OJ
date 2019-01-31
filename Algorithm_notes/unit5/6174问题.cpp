#include <cstdio>
#include <algorithm>

using namespace std;

// 数字 => 数组
void num_to_array(int a[], int n) {
	int i = 0;
	while(n > 0) {
		a[i++] = n % 10;
		n /= 10;
	}
}


// 固定数组使用4位
int array_to_num(int a[]) {
	int n = 0;
	for (int i = 0; i < 4; ++i)
	{
		n = n * 10 + a[i];
	}
	return n;
}

bool cmp_min(int a, int b) {
	return a < b;
}

bool cmp_max(int a, int b) {
	return a > b;
}

int main(int argc, char const *argv[])
{
	int n, max, min;
	scanf("%d", &n);
	int a[5];

	do{
		num_to_array(a, n);
		sort(a, a+4, cmp_min);
		min = array_to_num(a);
		sort(a, a+4, cmp_max);
		max = array_to_num(a);
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);
	}while(n != 0 && n != 6174);

	return 0;
}