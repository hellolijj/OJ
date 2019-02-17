#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s(10, 'x');

    string s1 = "hellloasldfja;sdjfa;";
    
    string s2(s1);
    string s3 = s1;

    string s4(s1, 2, 5);   //llloa
    string s5(s1, 2);      // llloasldfja;sdjfa;
    string s60("sfsdfa");    // 定义字符串
    string s6("sfsdfa", 4);    // 定义字符串
    

    char s7[21] = "sdfafdafasdfa";
    string s8("sfsdfa", 4);


    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << "  "<< s8<< endl;

}