#include <cstdio>

int partition(int a[], int left, int right) {
	int temp = a[left];
	while(left < right) {
		while(left < right && a[right] > temp) {
			right --;
		}
		a[left] = a[right];
		while(left < right && a[left] <= temp) {     // 这里取 == 是为什么？
			left++;
		}
		a[right] = a[left];
	}
	a[left] = temp;
	return left;
}

void quick_sort(int a[], int left, int right) {
	if (left < right)
	{
		int pos = partition(a, left, right);
		quick_sort(a, left, pos-1);
		quick_sort(a, pos+1, right);
	}
}


int main(int argc, char const *argv[])
{
	/* code */
    int a[11] = {2, 4, 7, 8, 9, 0, 6, 5, 3, 1};
    quick_sort(a, 0, 9);
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
	return 0;
}

    // 注意：
    // 快速排序的时间复杂度 ologn,快速排序适用于分散的比较散的值排序
    // 在分区函数中， 第二个移动指针判断条件 while(left<right&&a[left] >= temp) 这里使用了 >=