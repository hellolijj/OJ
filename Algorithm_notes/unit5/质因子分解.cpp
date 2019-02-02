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

struct factor
{
	int x;  // 某个质数
	int cnt = 0;   // 该质数出现的次数
}fac[10];

int main(int argc, char const *argv[])
{
    generate_prime_table();

    int n, fac_n = 0;   // fac_n 为第n个质因子
    scanf("%d", &n);
    
    if(n == 1) {
        printf("1=1\n");
    } else {
        // todo next things. 求数字的因子
        int sqr = (int)sqrt(n);

        // 枚举sqrt(n)以内的质因子
        for (int i = 0; i < prime_count && prime_table[i] <= sqrt(n); ++i)
        {
        	if (n % prime_table[i] == 0)
        	{
        		fac[fac_n].x = prime_count[i];
        		
        		// 记录该质因子出现的个数
        		while(n % prime_table[i] == 0) {
        			n = n / prime_table[i];
        			fac[fac_n].cnt ++;
        		}
        		fac_n++;
        	}

        }
    }

	for (int i = 0; i < prime_count; ++i)
	{
		printf("%d \n", prime_table[i]);
	}
	return 0;
}

/*
这道题目有些复杂，暂时还没有搞懂...
*/
