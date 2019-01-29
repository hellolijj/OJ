#include <cstdio>

// 输入一系列数字，用这些数字组成一个最小的数字


int main(int argc, char const *argv[])
{
	/* code */
	int count[10] = {0};  // 记录0～9的个数

	int a[10];      // 输入10个数字

	for (int i = 0; i <= 10; ++i)
	{
		scanf("%d", &a[i]);
		count[a[i]]++;
	}

    for (int i = 1; i <= 9; i++) {
        if(count[i] > 0) {
            printf("%d", i);
            count[i]--;        // 输出来了1个，加下来的慢慢输出
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) {
            printf("%d", i);
        }
    }
    printf("\n");

	// for (int i = 0; i < 10; ++i)
	// {
	// 	printf("%d", a[i]);
	// }

    // printf("\n"); 

	// for (int i = 0; i < 10; ++i)
	// {
	// 	printf("%d:%d\n", i, count[i]);
	// }
	return 0;
}