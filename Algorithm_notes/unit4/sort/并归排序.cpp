#include <cstdio>

// 合并思路：借助第三方数列，将两个有序数列合并到第三方数列
void merge(int a[], int left, int l_mid, int r_mid, int right) {
	int temp[100];
	int i = left, j = r_mid, k = 0;

	while(i <= l_mid && j <= right) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}

	while (i <= l_mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= right) {
		temp[k++] = a[j++];
	}
	
	// temp[] => a[]
	for (int i = 0; i < k; ++i)
	{
		a[left+i] = temp[i];
	}
}

void merge_sort(int a[], int left, int right) {
	if(left < right){
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid+1, right);
        merge(a, left, mid, mid+1, right);
    }
}

int main(int argc, char const *argv[])
{
	/* code */
    int a[10] = {2, 4, 7, 8, 9, 0, 6, 5, 3, 1};
    merge_sort(a, 0, 9);
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
	return 0;
}

// 总结：并归排序的简单思想是 分而治之 然后合并
// 时间复杂度 o(logn)
// 缺点就是 代码复杂度较高，一点点错误就正确结果出不来。