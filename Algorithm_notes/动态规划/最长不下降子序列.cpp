/* 最长不下降子序列问题
在一个数字序列中，找到一个最长对子序列可以不连续，使得这个子序列是不下降对

输入：
7
1 2 3 -1 -2 7 9
输出
5

输入
8
1 2 3 -9 3 9 0 11
输出
6
*/


#include <cstdio>

const int N = 101;
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int A[N];
    A[0] = 1;
    for(int i = 1; i < n; i++) {
        A[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] >= a[j] && A[j] + 1 > A[i]) {
                A[i] = A[j] + 1;
            }
        }
    }

    int max = -1;
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
        if(A[i] > max) {
            max = A[i];
        }
    }
    printf("%d\n", max);
}