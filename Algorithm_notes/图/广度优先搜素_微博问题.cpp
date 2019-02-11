#include <cstdio>
#include <queue>

using namespace std;

const int N = 1010;

struct Node
{
	int id;
	int layer;  // 图中节点所在层级
};

vector<Node> Adj[N];  // 使用邻接表来构造图

bool inq[N] = {false};     //来记录图中节点是否已经访问


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	// 输入每一个用户的follower
	for (int i = 1; i <= n; ++i)
	{
		Node user;
		user.id = i;

		int follower_cnt;
		scanf("%d", &follower_cnt);

		for (int j = 1; i <= follower_cnt; ++i)
		{
			int follower_id;
			scanf("%d", &follower_id);
			Adj[follower_id].push_back(user);
		}
	}

	return 0;
}

// 构造一个图，然后广度优先遍历