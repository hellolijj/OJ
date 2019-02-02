#include <cstdio>
#include <cstring>

struct Bign
{
	int d[1000];
	int len;
	Bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

// 将整数转换为bign
Bign change(char str[]) {

	Bign b;
	b.len = strlen(str);
	for (int i = 0; i < b.len; ++i)
	{
		b.d[i] = str[strlen(str)-i-1] - '0';
	}
	return b;
}

// 打印
void print(Bign n) {
	for (int i = 0; i < n.len; ++i)
	{
		printf("%c", n.d[n.len-i-1] + '0');
	}
}

// 两个大数相加
Bign add(Bign a, Bign b) {
	
	Bign c;
	int carry = 0; //进位
	for (int i = 0; i < a.len || i < b.len; ++i)
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[i] = temp % 10;
		carry = temp / 10;
		c.len++;
	}

	// 最高一位最后再判断
	if (carry > 0)
	{
		c.d[c.len++] = 1;
	}

	return c;
}

int main(int argc, char const *argv[])
{
	char a[1000], b[1000];
	scanf("%s%s", a, b);
	Bign big_a = change(a);
	Bign big_b = change(b);
	print(add(big_a, big_b));
	return 0;
}