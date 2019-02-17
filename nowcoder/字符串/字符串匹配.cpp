#include <cstdio>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

/* 题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

思路一：
使用队列做

思路二：
使用string 的特性做
string.find(" ", ops);
string.replace(ops, len, "%20")

思路三：使用两次遍历
如果发现 ' '
改变长度，所有的元素后移动
然后添加想要替换的元素
*/

class Solution {
public:
    // 使用队列，
    void replaceSpace(char *str,int length) {    
        queue<char> q;
        for(int i = 0; i < length; i++) {
            if(str[i] == ' ') {
                q.push('%');
                q.push('2');
                q.push('0');
            } else {
                q.push(str[i]);
            }
        }
        int i = 0;
        while(!q.empty()) {
            str[i++] = q.front();
            q.pop();
        }
	}

    void replaceSpace_2(char* str, int length) {
        string s(str);
        int next_find = 0;

        while(s.find(" ", next_find) != -1) {
            next_find = s.find(" ", next_find);
            s.replace(s.find(" ", next_find), 1, "%20");
        }
        
        // string ==> char *   s.c_str()
        strcpy(str, s.c_str());
    }

    void replaceSpace_3(char* str, int length) {
        int new_length = length;
        for(int i = 0; i < length; i++) {
            if(str[i] == ' ') {
                new_length += 2;
                for(int j = new_length-1; j > i; j--) {
                    str[j] = str[j-2];
                }
                str[i] = '%';
                str[i+1] = '2';
                str[i+2] = '0';
            } 
        }
    }
};

int main() {
    
    char s[30] = "We Are Happy";
    int length = strlen(s);
    
    class Solution Solu;
    Solu.replaceSpace_2(s, length);

    printf("%s\n", s);
    
    return 0;
}
