#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s(10, 'x');

    // string::npos

    string str = "lijj is my name";
    string name = "lijj";

    // str.find(name) 如果查到则返回 第一次出现的位置，否组返回 string::npos 也就是-1
    if(str.find(name) != string::npos) {
        cout << str.find(name) << endl;
        // printf("%s\n", str.find(name).c_str());
    }

    // 从str 的 2 位置开始查找
    str.find(name, 2);



    // 替换

    // replace(pos, len, str_new);
    cout << str.replace(str.find("is"), string("is").length(), "is not"); // strlen("is")
   
    return 0;
}

/*
string find() 的时间复杂度 o(mn)
*/