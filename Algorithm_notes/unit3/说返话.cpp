#include<cstdio>
#include<cstring>

int main(int argc, char const *argv[])
{
	char str[90]; 
	// scanf("%s", str);
    gets(str);

    char ans[90][90];
    int a = 0, b = 0;

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] != ' ') {
            ans[a][b] = str[i];
            b++;
        } else {
            ans[a][b] = '\0';
            a++;
            b = 0;
        }
    }
    for(int i = a; i >=0; i--) {
        if(i == 0) {
            printf("%s", ans[i]);
        } else {
            printf("%s ", ans[i]);
        }
        
    }		
	printf("\n");
	return 0;
}

// 总结，这个题目最关键的是如何使用二维数组存储输入的一句话。
// 然后这个题目输入，gets(str)， 与scanf("%s")区别很大