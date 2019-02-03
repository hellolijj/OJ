#include <cstdio>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
	int a = 1, b = 2, c = 3;
	
	// max 函数的使用
	printf("%d\n", max(max(a, b), c));

	// min 函数的使用
	printf("%d\n", min(min(a, b), c));


	// swap
	swap(a, b);
	printf("%d %d\n", a, b);

	return 0;
}