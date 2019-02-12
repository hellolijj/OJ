// 输出最短路径点条数, 及最短路径点权最大
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 101;
const int INF = 1000000000;

int n, m, s, e, G[N][N], W[N];  // n个点， m条边， s是起点， e是终点，G是邻接矩阵, W每一个节点的点权

int d[N];   // 存最短路径
int d_c[N];   // 存最短路径的条数
int w[N];     // 存最大点权

bool vis[N] = {false};   // 记录是否访问

void dijkstr(int s) {
    fill(d, d + N, INF);
    fill(d_c, d + N, 0);
    fill(w, w+n, 0);

    d[s] = 0;
    d_c[s] = 1;
    w[s] = W[s];

    for(int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < INF) {
                min = d[j];
                u = j; 
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    d_c[v] = d_c[u];
                    w[v] = w[u] + W[v];
                } else if(d[u] + G[u][v] == d[v]) {
                    d_c[v] += d_c[u];
                    if(w[v] < w[u] + W[v]) {
                        w[v] = w[u] + W[v];
                    }
                }
            }
        }
    }
}

int main() {
    fill(G[0], G[0]+N*N, INF);

    scanf("%d%d%d%d", &n, &m, &s, &e);
    for(int i = 0; i < n; i++) {
        scanf("%d", &W[i]);
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = w;
        G[v][u] = w;    // 因为是无方向的邻接矩阵
    }
    dijkstr(s);
    // for(int i = 0; i < n; i++) {
    //     printf("%d", d[i]);
    // }
    // printf("\n");
    // for(int i = 0; i < n; i++) {
    //     printf("%d", d_c[i]);
    // }
    printf("%d %d\n", d_c[e], w[e]);

    return 0;
}

/*
输入
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
输出
2 4
todo 
1、双向列表
2、最短路径条数
*/