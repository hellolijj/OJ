#include <cstdio>
#include <algorithm>

using namespace std;

/*
连续子数组的最大和

思路：动态规划
动态规划方程
*/

int main() {
    int a[8] = {1,-2,3,10,-4,7,2,-5};
    

    int A[8];
    A[0] = -2;
    for(int i = 1; i < 8; i++) {
        A[i] = max(a[i], A[i-1]+a[i]);
    }

    for(int i = 0; i <8; i++) {
        // printf("%d ", A[i]);
    }
    int max_v = A[0];
    for(int i = 0; i < 8; i++) {
        if(max_v < A[i]) {
            max_v = A[i];
        }
    }

    
    printf("\n最大值：%d\n", A[7]);
    return 0;
}