#include <cstdio>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	set<int> st;
	for (int i = 1; i <= 3; ++i)
	{
		st.insert(i);
	}

    // 输出 st.size() 的大小 返回值是 %lu unsign int
    printf("%d", (int)st.size());

    // 对set 元素的访问
    for(set<int>::iterator it = st.begin(); it != st.end(); it++) {
    	printf("%d ", *it);
    }

    // find() 返回元素的迭代器,时间复杂度 ologn

    printf("%d\n", *(st.find(2)));
	
    // erase() clear 的用法 同 vector
	return 0;
}