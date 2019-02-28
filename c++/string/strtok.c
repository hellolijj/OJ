#include <stdio.h>
#include <string.h>

int main() {
    char str[30] = "my name is lijj";
    char *p = strtok(str, " ");
    while(p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, " ");
    }
    return 0;
}

// 使用 strtok 函数分割字符串
// char *strtok(char *s, const char *delim);