#include <cstdio>
#include <cmath>

const int MAX_N = 1010;

// 判断正证书n 是否为质数
bool is_prime(int n) {
	if (n <= 1) {
		return false;
	} else {
		int k = sqrt(n);
		for (int i = 2; i <= (int)sqrt(n); ++i) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
}

int prime_table[MAX_N], prime_count = 0;
// 生成素数表
void generate_prime_table() {

	for (int i = 2; i < MAX_N; ++i)
	{
		if (is_prime(i))
		{
			prime_table[prime_count++] = i;
		}
	}
}

int main(int argc, char const *argv[])
{
    generate_prime_table();

    int n;
    scanf("%d", &n);
    if (n == 1) {
    	printf("1=1");
    }
    

	for (int i = 0; i < prime_count; ++i)
	{
		printf("%d \n", prime_table[i]);
	}
	return 0;
}