#include <cstdio>



int main(int argc, char const *argv[])
{
	int T;
	int pat[10000] = {0};
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int sid, score;
		scanf("%d %d", &sid, &score);
		pat[sid-1] += score;
	}

	int max_score = -1, k = -1;

	for (int i = 0; i < T; ++i)
	{
		if(pat[i] > max_score) {
			max_score = pat[i];
			k = i + 1;
		}
	}

	printf("%d %d\n", k, max_score);
	return 0;
}