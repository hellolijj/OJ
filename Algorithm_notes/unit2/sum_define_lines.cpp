#include <cstdio>

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int num_counts, sum = 0, num;
		scanf("%d", &num_counts);
		while(num_counts--) {
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
	}
	return 0;
}