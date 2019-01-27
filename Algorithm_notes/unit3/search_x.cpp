#include <cstdio>
const int N = 210;
int a[N];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	
	// input
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}

    int key;
    scanf("%d", &key);

	// to search num
    for (int i = 0; i < n; ++i) {
        if(a[i] == key) {
            printf("%d", i);
            return 0;
        }
    }

    printf("%d\n", -1);
	

	return 0;
}

// 总结，此程序使用了带用哨兵的顺序查找法
// 没有使用哨兵，两条判断，i<n, a[i]==key
// 使用了哨兵，一条判断，while(a[i]!=key)
// 哨兵的使用就是在第一个元素设置为要查找的元素，即将要查找到值放在边界。
// 随后设置查找列表。
// 如果返回为0，则就是没有查找到。
/*

int key;
scanf("%d", &key);
a[0] = key;  // 设置哨兵
int i = n-1;
while(a[i] != key) {
    i --;
}
printf("%d\n", i);
*/