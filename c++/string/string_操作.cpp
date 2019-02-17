#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s(10, 'x');
    string s1 = "hellloasldfja;sdjfa;";

    // 可直接比大小
    if(s == s1){
        cout <<  "等" << endl;
    }else if(s > s1) {
        cout << "大" << endl;
    }else {
        cout << "小" << endl;
    }

    // insert的两种用法
    s.insert(3, "sd");    // 使用下标位置添加字符串
    s.insert(s.end(), s1.begin(), s1.end());  // 使用迭代器添加字符串
    cout << s << endl;

    // erase的用法
    s.erase(s.begin());    // 删除一个元素
    // erase(first, last)
    s.erase(s.begin(), s.begin()+3);    // 删除一个区间元素 
    // erase(pos, length)
    s.erase(3, 9);


    cout << s << endl;

    // substr
    cout << s.substr(0, 3) << endl;
    

    return 0;
}