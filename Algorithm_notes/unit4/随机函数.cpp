#include <cstdio>
#include <cstdlib>
#include <time.h>


// 普通的随机函数
void oral_rand()
{
    srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", rand());
	}
	
}

// 随机函数 3～7
// rand() % (b-a+1)+a
void oral_rand_3_7() {
    srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", rand() % (7-3+1) + 3);
	}	
}
int main(int argc, char const *argv[])
{
	oral_rand_3_7();
}