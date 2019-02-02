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
	
	if(n.len <= 0) {
		printf("0");
	}
	printf("\n");
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

// 比较两个大数， a > = < b 分别返回 1， 0， -1
int compare(Bign a, Bign b) {

	if (a.len > b.len) {
		return 1;
	} else if(a.len < b.len) {
		return -1;
	} else {
		for (int i = 0; i < a.len; ++i)
		{
			if (a.d[a.len-1] > b.d[b.len-1]) {
				return 1;
			} else if(a.d[a.len-1] > b.d[b.len-1]) {
				return -1;
			}
		}
		return 0;
	}
}

// 两个大数字相减去
// 这里默认 a > b。 如果 a < b的话，则交换ab,对结果输出负值
Bign sub(Bign a, Bign b) {

	if(compare(a, b) < 0) {
		Bign temp;
		// 结构体内容的交换
		/*
		temp = a;
		a = b;
		b = temp;
		*/
	}

	Bign c;
	for(int i = 0; i < a.len || i < b.len; i++) {
		if (a.d[i] < b.d[i])
		{
			a.d[i] += 10;
			a.d[i+1] --;
		}
		c.d[i] = a.d[i] - b.d[i];
		c.len++;
	}

	// 对最高位相减为0的特殊情况进行处理: c的长度减下来
	while(c.d[c.len-1] == 0) {
		c.len--;
	}
	// 对a-b=0这种情况，特殊处理
	
	return c;
}

int main(int argc, char const *argv[])
{
	char a[1000], b[1000];
	scanf("%s%s", a, b);
	Bign big_a = change(a);
	Bign big_b = change(b);
	print(add(big_a, big_b));
	print(sub(big_a, big_b));
	printf("%d\n", compare(big_a, big_b));
	return 0;
}