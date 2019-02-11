// 求最短路径、最短路径长度、最少花费
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 501;
const int INF = 1000000000;

// n个点 m条边 起点s 终点e G保存有向图 保存花费
int n, m, s, e, G[N][N], C[N][N];

int d[N];     // 保存最短路径
int c[N];      // 保存最短路径的花费
int pre[N];

bool vis[N] = {false};  // 保存是否访问

vector<int> path;

void disjkstr(int s, int e) {

    fill(d, d+n, INF);
    fill(c, c+n, INF);

    for(int i = 0; i < n; i++) pre[i] = i;

    d[s] = 0;
    c[s] = 0;

    for(int i = 0; i < n; i++) {

        int u = -1, d_min = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < d_min) {
                d_min = G[s][j];
                u = j;
                vis[u] = true;
            }
        }
        if(u == -1) return;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v] = u;
                    c[v] = c[u] + C[u][v];
                } else if (d[u] + G[u][v] == d[v]) {
                    if(c[u] + C[u][v] < c[v]) {
                        c[v] = c[u] + C[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }

}

void dfs(int u, int v) {

    if(u == v) {
        path.push_back(u);
        return;
    }

    dfs(u, pre[v]);
    path.push_back(v);
}

int main() {

    fill(G[0], G[0] + N * N, INF);
    fill(C[0], C[0] + N * N, INF);
    
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for(int i = 0;i < m; i ++) {
        int u, v, w, c;
        scanf("%d%d%d%d", &u, &v, &w, &c);
        G[u][v] = w;
        C[u][v] = c; 
    }

    disjkstr(s, e);
    dfs(s, e);

    for(int i = 0; i < path.size(); i++) {
        printf("%d ", path[i]);
    }

    printf("%d %d\n", d[e], c[e]);
    return 0;
}

/*
输入
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
输出
0 2 3 3 40
*/