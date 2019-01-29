#include <cstdio>

/**
 * 二分查找方法，数组a, left左侧下标， right 右侧下标，要查找的数字是x
 * 时间复杂度是 O(logn)
 **/
int binary_search(int a[], int left, int right, int x)
{
	int mid;       // mid 是left right 下标的中点
	while(left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == x) {
			return mid; 
		} else if (a[mid] > x) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return -1;

}

int main(int argc, char const *argv[])
{
	int a[10] = {1, 3, 5, 7, 9, 11, 13, 14, 15, 18};

	printf("%d\n", binary_search(a, 0, 9, 0));


	return 0;
}

// 总结：二分查找方法时间复杂度 o(logn)
// mid 为下标，要么返回 mid 要么 mid = left + 1 or right + 1

// 注意⚠️： 在二分查找方法中，left + right 有可能会超过 int 的上界，可食用 mid = left + (right-left)/2来代替

// 查找第一次大于等于x的元素的位置
int lower_search(int a[], int left, int right, int x) {

	int mid;
	while(left < right) {
		mid = left + (right - left) / 2;
		if(a[mid] >= x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}

	return left;
}