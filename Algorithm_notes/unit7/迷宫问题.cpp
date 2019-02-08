// 求一个迷宫里，从一个点到另一个点的最短步数

#include <cstdio>
#include <queue>

using namespace std;

const int N = 30;

int m, n;     // 矩阵大小 m * n
char maze[N][N];      // 记录迷宫信息

struct Node
{
	int x, y;
	int step; // step 为从起点s到达该位置最短需要多少步

}S, T, Temp;

bool inq[N][N] = {false};     // 判断 点 x,y 是否已经入列

int X[4] = {0, 0, 1, -1};      // 增量数组
int Y[4] = {1, -1, 0, 0};

// 检测 x y位置是否有效
bool test(int x, int y) {
    if (x >= m || x < 0 || y >= n || y < 0)
	{
		return false;
	}

	// 墙壁 *
    if (maze[x][y] == '*') {
    	return false;
    }

    // 已经入列
    if (inq[x][y] == true)
    {
    	return false;
    }

    // 有效位置
    return true;
}



int BFS(){
	queue<Node> q;
	q.push(S);
	while(!q.empty()) {
		Node top = q.front();
		q.pop();

		if (top.x == T.x && top.y == T.y)
		{
			return top.step;
		}

		for (int i = 0; i < 4; ++i)
		{
			int new_x = top.x + X[i];
			int new_y = top.y + Y[i];
			if (test(new_x, new_y))
			{
				Temp.x = new_x;
				Temp.y = new_y;
				Temp.step = top.step + 1;
				q.push(Temp);
				inq[new_x][new_y] = true;
			}
		}
	}

	return -1;
}


int main(int argc, char const *argv[])
{
	scanf("%d%d", &m, &n);

	// 读入 01 矩阵
	for (int i = 0; i < m; ++i)
	{
		getchar();  // 过滤掉每行后面的换行符
		for (int j = 0; j < n; ++j)
		{
			maze[i][j] = getchar();
		}
		maze[i][n+1] = '\0';
	}

	scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);     // 起点和终点的坐标
	S.step = 0;

	printf("%d\n", BFS());
	return 0;
}