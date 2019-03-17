#include <cstdio>
#include <algorithm>

using namespace std;

extern void swap_with_zero(int* array, int len, int n);

class Solution {
public:
    /**
     * 调用方法swap_with_zero来对array进行排序
     */
    void sort(int* array, int len) {
        if(len <= 0) {
            return;
        }

        for(int i = len - 1; i > 0; i --)
        {
            if(array[i] == i)      
                continue;
            swap_with_zero(array, len, array[i]);    //交换0与i位置的数字 
            swap_with_zero(array, len, i);           //交换0与i
        }
    }
};

int main() {
    int a[5] = {4,3,2,1,0};
    class Solution solu;
    solu.sort(a, 5);
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}