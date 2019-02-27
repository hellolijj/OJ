/*把字符串转换成整数

题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
复制
+2147483647
    1a33
输出
复制
2147483647
    0

test case
0       0
-0     0
+0       0
ad23     0
24231i   0
空       0
*/
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

bool valid(char c) {
    if(c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

int StrToInt(string str) {
    if(str.length() == 0) {
        return 0;
    }
    bool flag = true;   //true 表示正数 false 表示负数
    if(str[0] == '-') {   
        flag = false;
        str.erase(str.begin());
    }
    if(str[0] == '+') {   
        str.erase(str.begin());
    }
    int res = 0;
    for(int i = 0; i < str.length(); i++) {
        if(!valid(str[i])) {
            return 0;
        }
        res = res * 10 + str[i] - '0';
    }
    return flag ? res: 0-res;
}

/*
合法字符
0 1 2 3 4 5 6 7 8 9 + - 
*/

int main() {
//     0       0
// -0     0
// +0       0
// ad23     0
// 24231i   0
// 34253442503452 超过最大值
// 空       0
    printf("%d\n", StrToInt("0"));
    printf("%d\n", StrToInt("-0"));
    printf("%d\n", StrToInt("+0"));
    printf("%d\n", StrToInt("ad123"));
    printf("%d\n", StrToInt("+342534"));
    printf("%d\n", StrToInt("34253442503452"));
    printf("%d\n", StrToInt("3425 34"));
    printf("%d\n", StrToInt(""));
    return 0;
}