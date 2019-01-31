#include <cstdio>
int gcd(int m, int n) {

	// 交换 
	if(m < n) {
		int temp = m;
		m = n;
		n = temp;
	}

	if (m % n == 0)
	{
		return n;
	}

	return gcd(n, m-n);
}

int main(int argc, char const *argv[])
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d %d, 的最大公约数: %d\n", m, n, gcd(m,n));
	return 0;
}
// 最大公约数和最小公倍数的计算方法：1、辗转相除法 2、递归方法


// 还有更简单写法
// a > b;
/*
int gcd(int a, int b) 
{
	if(b == 0) return a;
	return gcd(a-b, b)
}
*/

// 最小公倍数的求法，a * b / ab的最大公约数