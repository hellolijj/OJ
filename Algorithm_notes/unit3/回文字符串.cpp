#include <cstdio>
#include <cstring>
const int maxn = 256;
char str[maxn];

bool isHuiwen(char s[]) {
	int len = strlen(s);

	for (int i = 0; i < len / 2; ++i)
	{
		if (s[i] != s[len-i-1])
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	while(scanf("%s", str) != EOF) {
		if (isHuiwen(str)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}	
	}
	return 0;
}