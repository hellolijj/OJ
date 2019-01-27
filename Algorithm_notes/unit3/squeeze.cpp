/*
画正方形状
*/
#include <cstdio>

int main() {
    int col, raw;  
    char c;
    scanf("%d %c", &col, &c);
    raw = (col+1) / 2;  // 行取列一半的四舍五入
    
    for(int i = 0; i < raw; i++) {
        if(i == 0 || i == raw-1) {    // 第一行或者最后一行
            for(int j = 0; j < col; j++) {
                putchar(c);
            }
            puts("");                 // 打印下一行，相当于 printf("\n");
        } else {
            for(int j = 0; j < col; j++) {
                if(j == 0 || j == col-1) {
                    putchar(c);
                } else {
                    printf(" ");
                }
            }
            puts("");
        }


    }
    


    return 0;
}

// 总结：
// 此类打印题目，
// 1 可以按照题目要求一行一行一个字符一个字符的处理
// 2、也可以安装数组的规律处理打印