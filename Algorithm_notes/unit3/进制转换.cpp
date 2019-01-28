#include<cstdio>

// n进制转10进制,a 输入的数字，n表示这个数字是几进制的。
// todo 对传入的参数进行判断
int x_to_10(int x, int n) {
	int y = 0, p = 1;   // 每一次循环是对每一个位数进行操作，每一位数乘以 n 的进制次幂
	while(x != 0) {
		y = y + (x % 10) * p;     // x % 10是取每个数字的个位数
		x = x / 10;               // 去掉个位数
        p = p * n;
	}
	return y;
}

// 10进制转为其他进制
void x10_to_n(int x, int n) {

    int z[40] = {-1},i = 0;
    do{
        z[i++] = x % n;
        x = x / n;
    }while(x != 0);

    while(i-- > 0) {
        printf("%d", z[i]);
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
	x10_to_n(100, 2);
	return 0;
}