#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int N = 1010;

struct Node
{
	int id;
	int layer;  // 图中节点所在层级
};

vector<Node> Adj[N];  // 使用邻接表来构造图

bool inq[N] = {false};     //来记录图中节点是否已经访问

// bfs 遍历 s 表示起点， l是遍历的层数
int BFS(int s, int l) {

	int forward_cnt = 0;

	queue<Node> q;
	
	Node start;
	start.id = s;
	start.layer = 0;

	q.push(start);
	inq[s] = true;

	while(!q.empty()) {
		Node top = q.front();
		q.pop();

		int u = top.id;

		// 遍历邻接元素
		for (int i = 0; i < Adj[u].size(); ++i)
		{
			Node next = Adj[u][i];  // 取出这个元素的follower
			next.layer = top.layer + 1;

			if (inq[next.id] == false && next.layer <= l)
			{
				q.push(next);
				inq[next.id] = true;
				// printf("%d ", next.id);
				forward_cnt++;
			}
		}
	}

	printf("\n");
	return forward_cnt;
}

int main(int argc, char const *argv[])
{
	int n, l;
	scanf("%d%d", &n, &l);
	
	
	// 输入每一个用户的follower
	for (int i = 1; i <= n; ++i)
	{
		Node user;
		user.id = i;

		int follower_cnt;
		scanf("%d", &follower_cnt);

		for (int j = 1; j <= follower_cnt; ++j)
		{
			int follower_id;
			scanf("%d", &follower_id);
			Adj[follower_id].push_back(user);
		}
	}

	int query_times;
	scanf("%d", &query_times);
	for(int i = 0; i < query_times; i++) {
		int query_id;
		scanf("%d", &query_id);

		printf("%d\n", BFS(query_id, l));
	}

	return 0;
}

// 构造一个图，然后广度优先遍历