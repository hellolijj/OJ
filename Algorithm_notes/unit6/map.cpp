#include <cstdio>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	map<char, int> mp;
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		printf("%c %d\n", it -> first, it -> second);
	}

    // find() 函数的使用 find() 传入的参数为键
    map<char, int>::iterator i = mp.find('b');
    printf("%c, %d\n", i->first, i->second);

    // erase 函数 传入迭代器, 也可以删除一个区间里的元素
    mp.erase(i);

	return 0;
}

// mp->first mp->second 分别输出当前映射的键，值