//  求一个数组中，其他的元素都是两两相同，有一个元素跟其他不一样，求这个元素


#include <cstdio>

int main()
{
    int a[9] = {1, 2, 3, 4, 6, 4, 3, 2, 1};

    int res = 0;
    for(int i = 0; i < 9; i++) {
        res = res ^ a[i];
    }

    printf("%d\n", res);
    return 0;
}

// 说明 ： a ^ 0 = a。 a ^ a = 0 ^ 是相异操作