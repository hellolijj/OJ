// 问题： 有n个物品 每件物品重量w[i], 价值c[i]。选出若干物品放入一个容器为V的背包中，
// 使得选入背包物品重量和不超过容量V的前提下，让背包午评的价值最大，求出最大值。

// 背包问题、深度优先搜索问题、栈的问题


#include <cstdio>

const int N = 10;

int n, v, max = 0;    // n 表示物品件数， v表示不能超过的总容量, max 表示最大价值
int w[N], c[N];

// sum_w 表示当前总重量，sum_c表示当前总价值
// void DFS(int index, int sum_w, int sum_c) {

// 	if(index == n && sum_c > max && sum_w <= v) {
// 		max = sum_c;
// 		return;
// 	}
// 	DFS(index+1, sum_w, sum_c);
// 	DFS(index+1, sum_w + w[index], sum_c + c[index]);
// }

// 经过剪枝后的 DFS 上的的dfs 复杂度较高，无法运行通过。因此在此函数中添加些条件，才可以运行
void DFS(int index, int sum_w, int sum_c) {

	if(index == n) {
		return;
	}

	DFS(index+1, sum_w, sum_c);

	if(sum_w + w[index] <= v) {
		if(sum_c + c[index] > max) {
			max = sum_c + c[index];
		}
		DFS(index+1, sum_w + w[index], sum_c + c[index]);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &c[i]);
	}
	DFS(0, 0, 0);
	printf("%d\n", max);
	return 0;
}