#include <cstdio>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	
	stack<int> st;
	for (int i = 1; i <= 5; ++i)
	{
		st.push(i);
	}

	// 取出栈顶元素
	printf("%d\n", st.top());

    // 出栈
    st.pop();
    printf("%d\n", st.top());

	return 0;
}