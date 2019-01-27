#include <cstdio>

int main(int argc, char const *argv[])
{
	int n, step = 0;
	scanf("%d", &n);
	while(n != 1) {
		if(n % 2 == 0) {
			n /= 2;
		} else {
			n = (n * 3 + 1) / 2;
		}
		step ++;
	}
	printf("%d\n", step);
	return 0;
}