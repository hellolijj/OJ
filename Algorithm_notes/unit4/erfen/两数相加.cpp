#include<cstdio>

int main(int argc, char const *argv[])
{
	int a[16] = {1, 2, 3, 4, 5, 7, 7, 8, 10, 12, 13, 15, 17, 18, 19, 20};
	int i = 0, j = 15, target = 13;
	while(i < j) {
		if (a[i]+a[j] == target) {
			printf("%d %d\n", a[i], a[j]);
			i ++;
			j --;
		} else if (a[i] + a[j] < target) {
			i ++;
		} else {
			j --;
		}
	}
	return 0;
}

// 总结：如果按照普通的想法，则需要两次遍历可能才想的出来
// 这个题目还有一个特征，就是已经拍好的序列