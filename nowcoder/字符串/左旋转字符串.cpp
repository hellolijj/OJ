/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

#include <cstdio>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.length() == 0) {
            return "";
        }
        queue<char> q;
        for(int i = 0; i < str.length(); i++) {
            q.push(str[i]);
        }
        
        for(int i = 0; i < n % str.length(); i++) {
            char temp = q.front();
            q.pop();
            q.push(temp);
        }
        string res = str;
        int i = 0;
        while(!q.empty()) {
            res[i++] = q.front();
            q.pop();
        }
        res[i] = '\0';
        return res;
    }

    string LeftRotateString1(string str, int n) {
        int len = str.length();
        if(len == 0) return "";
        n = n % len;
        str += str;
        return str.substr(n, len);
    }
};

int main() {
    class Solution solu;
    cout << solu.LeftRotateString("", 0) << endl;
    return 0;
}

/*

注意边界条件

方法二：简介明了
*/