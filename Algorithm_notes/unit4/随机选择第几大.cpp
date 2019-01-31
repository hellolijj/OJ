#include <cstdio>

int partition(int a[], int left, int right) {
    int temp = a[left];
    while(left < right) {
        while(left < right && a[right] > temp) {
            right--;
        }
        a[left] = a[right];
        while(left < right && a[left] <= temp) {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}

// 在数组a中查找第k大的元素
int rand_select(int a[], int left, int right, int k) {
	if(left == right) {
		return a[left];
	}
	int p = partition(a, left, right);
	int m = p-left+1;
	if(m == k) {
		return a[p];
	} else if(m < k){
		return rand_select(a, p+1, right, k-m);
	} else {
		return rand_select(a, left, p-1, k);
	}
}

int main(int argc, char const *argv[])
{
	int a[10] = {2, 4, 7, 8, 9, 0, 6, 5, 3, 1};

	printf("第%d大的值为: %d\n", 5, rand_select(a, 0, 9, 5));
	return 0;
}