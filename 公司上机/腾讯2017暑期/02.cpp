/*
小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？

输入描述:

输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  
输出描述:

对于每组数据，输出移位后的字符串。

输入例子1:
AkleBiCeilD

输出例子1:
kleieilABCD

*/
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while(cin >> s) {
        int len = s.length();
        for(int i = 0; i < len-1; i++) {
            for(int j = 0; j < len-1-i; j++) {
                // j大写
                if(s[j] >= 'A' && s[j] <= 'Z' && s[j+1] >= 'a' && s[j+1] <= 'z') {
                    swap(s[j], s[j+1]);
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}