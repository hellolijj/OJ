// 弗洛伊德算法，解决图中全源最短路径 非负数路径

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 101;
const int INF = 100000000; // 最大值表示不可到达

int n, m, G[N][N];   // n个顶点 m条边 G表示邻接举证

void floyd() {
    for(int k = 0; k < n; k ++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(G[i][k] != INF && G[k][j] != INF && G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
}

int main() {
    fill(G[0], G[0]+N*N, INF);
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++) G[i][i] = 0;  // 初始化自己到自己的距离是0
    
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = w;
    }
    floyd();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%15d", G[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
错误点注意
G[i][j] 不一定要 直连
if(G[i][k] != INF && G[k][j] != INF && G[i][j] != INF && G[i][k] + G[k][j] < G[i][j]) {
    G[i][j] = G[i][k] + G[k][j];
}
*/
/* 
输入
6 8
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3
输出

              0              1              5              3              4              6
      100000000              0              4              2              5              5
      100000000      100000000              0      100000000      100000000              1
      100000000      100000000              2              0              3              3
      100000000      100000000      100000000      100000000              0              3
      100000000      100000000      100000000      100000000      100000000              0

两点之间点最短距离
*/