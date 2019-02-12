#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 101;
const int INF = 100000000;

int n, m, G[N][N];
bool vis[N] = {false};

int d[N];

// s 是起点， 返回最小生成树的权重
int prim(int s) {
    fill(d, d + N, INF);

    d[s] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false  && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[u][v] != INF && d[v] > G[u][v]) {
                d[v] = G[u][v];
            }
        }
    }

    return ans;
}

int main() {

    scanf("%d%d", &n, &m);
    fill(G[0], G[0] + N * N, INF);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = w;
        G[v][u] = w;     // 无向图
    }

    printf("%d\n", prim(0));
    
    return 0;
}

/*
输入
6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3
输出
15
*/