/*有n件午评，每件物品重量w[i], 价值c[i]。
现有一个容量v的背包，问如何选取物品，使得背包的总价值最大。
其中每种物品可以有多件
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
const int maxv = 1000;
int c[maxn], w[maxn], dp[maxn];

int main() {
    int n, V;
    scanf("%d%d", &n, &V);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for(int v = 0; v <= V; v++) {
        dp[v] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int v = w[i]; v <= V; v++) {
            dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
        }
    }

    // get max
    int max = 0;
    for(int i = 0; i <= V; i++) {
        if(dp[i] > max) max = dp[i];
    }
    printf("%d\n", max);
}

/*输入
5 8
3 5 1 2 3
4 5 2 1 3
输出
16
*/