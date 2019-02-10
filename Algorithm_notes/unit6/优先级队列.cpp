// 默认情况下优先级队列先出来最大的元素

#include <cstdio>
#include <queue>

using namespace std;

// 自定义结构体优先级, 对 < 进行重新定义
// 此结构体是按照 fruit.price 从小到大的顺序排序的

struct fruit
{
	int name;
	int price;
	friend bool operator < (fruit f1, fruit f2) {
		return f1.price < f2.price;
	}
};

int main(int argc, char const *argv[])
{
	// priority_queue<int> q;    // 默认从大到小的优先级
    priority_queue<int, vector<int>, less<int> > q;    // 等同于 默认情况
    // priority_queue<int, vector<int>, greater<int> > q;    // 与默认情况相反
    
	q.push(1);
	q.push(100);
	q.push(10);
	q.push(34);
	
	for (int i = 0; i < 4; ++i)
	{
		printf("%d ", q.top());
		q.pop();
	}
	
	return 0;
}

