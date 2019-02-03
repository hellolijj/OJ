#include <cstdio>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
    q.push(4);
    q.push(5);

    // 获取队列的首，队列顶尾
	printf("%d %d\n", q.front(), q.back());

    // 出队列
    q.pop();

    printf("%d\n", q.front());

    if (!q.empty()) {
        printf("is not empty\n");
    }
	return 0;
}