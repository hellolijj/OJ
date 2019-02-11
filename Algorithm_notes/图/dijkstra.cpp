// 迪杰斯特拉算法, 单源最短路径问题， 亚历山大问题, 使用邻接数组实现

#include <cstdio>
#include <algorithm>

using namespace std;

// 邻接数组最大不超过1000
const int N = 1000; 
const int INF = 1000000000;  

int n, m, s, G[N][N]; // n个节点、m条边，s为起点， G为有向图

int d[N];     // 记录节点到所有节点的 最短距离
int pre[N];      // 记

bool vis[N] = {false};    // 记录节点是否被访问

void dijkstra(int s) {

	fill(d, d + n, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++) pre[i] = i;

	for (int i = 0; i < n; ++i)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; ++j)
		{
			if (vis[j] == false && d[j] < min)
			{
				min = G[s][j];
				u = j;
			}
		}
		if (u == -1)
		{
			return;  // 说明 s点 与该图G 不是连通的
		}
		vis[u] = true;
		for (int v = 0; v < n; ++v)
		{
			// 如果 v 不能访问 && u 能到达v && 以v为中介可以使得d更优
			if (vis[v] == false && G[u][v] != INF && G[u][v] + d[u] < d[v])
			{
				d[v] = G[u][v] + d[u];
				pre[v] = u;
			}
		}
	}
}

void dfs(int u, int v) {
	if(u == v) {
		printf("%d", u);
		return;
	} 

	dfs(u, pre[v]);
	printf("%d", v);

}

int main(int argc, char const *argv[])
{

	scanf("%d%d%d", &n, &m, &s);
	fill(G[0], G[0] + N * N, INF);       // 初始化图G

	for(int i = 0; i < m; i ++) {
		int u, v, w;      
		scanf("%d%d%d", &u, &v, &w); // 输入一条边的起点、终点、及边的权重
		G[u][v] = w;  
	}

	dijkstra(s);

	for (int i = 0; i < n; ++i)
	{
		printf("%d到%d的最短路径为:",s, i);
		dfs(s, i);
		printf(" 长度是%d", d[i]);
		printf("\n");
	}
	return 0;
}

/*
1、fill 函数可以把容器、数组某一个段区间赋值为某个相同的值
eg: fill(a, a + 5, 1000);  a[100];
eg: fill(a[0], a[0] + n * n, 100); a[][]
使用fill函数，需要先 引入 头文件  #include <algorithm>

2、使用邻接举证表示有向图 
G[u][v] = w; u是起点，v是终点，w是边的权重

*/