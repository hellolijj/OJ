#include <cstdio>
const int N = 11;

int p[N];
bool hashTable[N] = {false};

// 当前处理排列第 index 号位

void generateP(int index, int n) {

	if(index == n+1) {
		// 输出
		for (int i = 1; i < index; ++i)			
		{
			printf("%d", p[i]);
		}
		printf("\n");
	}

	for (int i = 1; i <= n; ++i)
	{
		if (hashTable[i] == false)
		{
			p[index] = i;
			hashTable[i] = true;
			generateP(index+1, n);
			hashTable[i] = false;        // 每一次排列完成后，标记位又标记为false
		}
	}
}

int main(int argc, char const *argv[])
{
	generateP(1, 2);
	return 0;
}

// 总结：
// 这个题目好难看懂，建议跳过去