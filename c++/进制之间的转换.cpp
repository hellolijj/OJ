#include <cstdlib>
#include <cstdio>

int main() {
    int a;
    char s[81];
    sscanf("123", "%d", &a);   // 以十进制的形式输入
    sprintf(s, "%0X", a);     // 以八进制输出
    puts(s);

    itoa(10,s,2)
    puts(s);

    return 0;
}

// %d 十进制
// %o 八进制
// %x 十进制 用 a b c d e f 表示超过9的数
// %X 十进制 用 A B C D E F 表示超过9的数
// %0d    0 不够的位数用于补0

// sscanf函数的用法与printf函数很像，都是以格式化的形式进行操作，例如如下的例子中，sscanf("A23CD", "%x", &a)