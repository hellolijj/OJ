#include <cstdio>

// 题意思。输入数字n, 接下来是n个数字的序列 和另外一个n 个数字的序列。
// 判断该序列是插入排序还是堆排序

const int N = 100;
int a[N];
int n;

// 向下调整
void down_adjust(int low, int hign) {

	int adjust_target = low;          // 欲调整节点的下标记
	int lchild = adjust_target * 2;     // 调整节点下标的左孩子

	while(lchild <= hign) {

		int rchild = lchild + 1;

		if (rchild <= hign && a[rchild] > a[lchild])
		{
			lchild = rchild;
		}
		// 至此 lchild 表示 a[lchild] a[rchild] 最大值的下标

		if (a[lchild] > a[adjust_target]) {

			int temp = a[lchild];
			a[lchild] = a[adjust_target];
			a[adjust_target] = temp;

			// 再进行与节点孩子的孩子进行比较
			adjust_target = lchild;
			lchild = 2 * adjust_target;
		} else {
			break;
		}
	}
}

// 建堆的过程

void creaet_heap() {
	for (int i = n / 2; i >= 1; --i)
	{
		down_adjust(i, n);
	}
}

void heap_sort() {
	creaet_heap();
	for (int i = n; i >= 1; --i)
	{
		down_adjust(1, i);
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
	}
}



int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}
	heap_sort();
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

// 堆的存储结构并不是使用链表来实现的，而是使用数组来实现的。
// 当前节点下标记为i, 起左节点下标为2 * i, 右节点下标为 2*i+1