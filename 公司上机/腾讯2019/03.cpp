#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000010;
const int M = 2010;

int a[N];

int dp[M] = {0}; // 表示i枪是连续第i种颜色
int dpn[M] = {0}; 

int main() {
    int n, m;
    scanf("%d%d", &n, &m); // n枪 m个气球
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // 暴力，第一步找到最后一个全部的数字
    int i, sum;
    for(i = 0; i < n; i++) {
        if(dp[a[i]] == 1) continue;
        sum += 1;
        dp[a[i]] = 1;
        if(sum == m) break;
    }
    // 找到i最后的位置  
    if(i == n) {
        printf("%d\n", -1);
        return 0;
    }
    // 从i往后找
    sum = 0;
    int j;
    for(int j = i; j >= 0; j--) {
        if(dpn[a[i]] == 1) continue;
        sum += 1;
        dp[a[j]] = 1;
        if(sum == m) break;
    }
    printf("%d\n", i - j);
}
/*
12 5
2 5 3 1 3 2 4 1 0 5 4 3
*/