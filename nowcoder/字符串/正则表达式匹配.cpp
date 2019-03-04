/*题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，
但是与"aa.a"和"ab*a"均不匹配
*/

#include<cstdio>
#include<cstring>

using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        // 1、str 为 null pattern 为 null
        if(*str == '\0' && *pattern == '\0') {
            return true;
        }
        // 2、str 不为 null pattern 为 null
        if(*str != '\0' && *pattern == '\0') {
            return false;
        }

        // 3 str 为null parttern不为null
        
        // 4 str 不为null parttern 不为 null
        // 4.1 *pattern 为 . 或者 某字符
        if(*(pattern+1) != '*') {
            if(*pattern == *str || (*str != '\0' && *pattern == '.')) {
                return match(str+1, pattern+1);
            } else {
                return false;   
            }
        } else {
            // 4.1.1 patter 为 * 表示 0个字符 和  patter 为 * 表示 1个或多个字符
            if(*pattern == *str || (*str != '\0' && *pattern == '.')) {
                return match(str, pattern+2) || match(str+1, pattern);
            } else {
                return match(str, pattern+2);
            }
        }
    }
};

int main() {
    class Solution solu;
    char s1[10] = "abbc";
    char s2[10] = "ab*c";
    if(solu.match(s1, s2)) {
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}

// 参考思路：https://www.nowcoder.com/questionTerminal/45327ae22b7b413ea21df13ee7d6429c
// 这个题目比较难，可以先放放