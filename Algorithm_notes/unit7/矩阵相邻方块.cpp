// 给定一个 0 1 矩阵，求矩阵的相邻方块数


#include <cstdio>

const int N = 100;

int m, n;     // 矩阵大小 m * n
int metrix[N][N];      // 存储 01 矩阵

int X[4] = {0, 0, 1, -1};      // 增量数组
int Y[4] = {1, -1, 0, 0};

int ans = 0;

// 判断 x y 是否可以访问
bool judge(int x, int y){
	if (x >= m || x < 0 || y >= n || y < 0)
	{
		return false;
	}
	
	return true;
}


bool is_lin(int x, int y) {

	if(!judge(x, y)) {
		return false;
	}
	if(metrix[x][y] == 0) {
		return false;
	}
	
	int new_judge_cont = 0;  // 相邻可访问的个数
	int new_lin_cont = 0;     // 相邻满足添加的个数
	for (int i = 0; i < 4; ++i)
	{
		int new_x = x + X[i];
		int new_y = y + Y[i];
		if(judge(new_x, new_y)) {
			new_judge_cont++;
			new_lin_cont += metrix[new_x][new_y];
		}
	}

	if(new_judge_cont > 0 && new_judge_cont == new_lin_cont) {
		return true;
	} 

	return false;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &m, &n);

	// 读入 01 矩阵
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &metrix[i][j]);
		}
	}
	for (int i = 0; i < m; ++i)	{
		for (int j = 0; j < n; ++j)
		{
			if (is_lin(i, j))
			{
				ans++;
			}	
		}
	}

	printf("%d\n", ans);
	return 0;
}