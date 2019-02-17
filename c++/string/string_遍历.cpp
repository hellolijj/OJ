#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    
    // s的定义
    string s = "nihoa";

    // s的输出
    cout << s << endl;
    printf("%s\n", s.c_str());

    // s的遍历
    for(int i = 0; i < s.length(); i++) {
        printf("%c", s[i]);
    }
    for(int i = 0; i < s.size(); i++) {
        printf("%c", s[i]);
    }
    for(string::iterator i = s.begin(); i != s.end(); i++) {
        printf("%c", *i);
    }
    printf("\n");

    


}