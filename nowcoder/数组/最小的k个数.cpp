/*题目描述
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，
则最小的4个数字是1,2,3,4,。

思路一：排序？
时间复杂度 o(nlogn)
并轨排序、快速排序、堆排序

思路二 ：利用快速排序中对partion 方法，实现topk方法
这样的topk 不一定就是已经排序好的
*/

#include <cstdio>
#include <vector>

using namespace std;

int partition(vector<int> &v, int left, int right) {
    if(v.empty()) {
        return 0;
    }
    int temp = v[left];

    while(left < right) {
        while(left < right && temp < v[right]) {
            right--;
        }
        v[left] = v[right];
        while(left < right && temp >= v[left]) {
            left++;
        }
        v[right] = v[left];
    }
    v[left] = temp;
    return left;
}

void quick_sort(vector<int> &vi, int left, int right) {

    if (left < right) {
        int ops = partition(vi, left, right);
        quick_sort(vi, left, ops-1);
        quick_sort(vi, ops+1, right);
    }

}
int main() {
    int a[6] = {4,5,7,6,1,2};
    vector<int> v(6);
    for(int i = 0; i < v.size(); i++) {
        v[i] = a[i];
    }

    quick_sort(v, 0, 5);

    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }

    return 0;
}