/* 
括号匹配 
 
给定一个字符串，里边可能包含“()”、“[]”、“{}”三种括号，请编写程序检查该字符串中的括号是否成对出现，且嵌套关系正确。 
输出：true:若括号成对出现且嵌套关系正确，或该字符串中无括号字符； 
false:若未正确使用括号字符。 
实现时，无需考虑非法输入。 
 
输入描述： 
输入为： 
字符串 
 
例子：(1+2)/(0.5+1) 
 
输出描述： 
输出为： 
字符串 
 
例子：true 

/*
思路：栈
遇到左符号，则压入，遇到右符号，弹出顶层的符号和右符号比对，如果符合，则继续，
否则输出false
*/ 

#include <iostream>
#include <vector>
#include <string>
using  namespace std;

int whatType(char ch){
    if(ch=='['||ch=='{'||ch=='('){
        return -1;
    }else if(ch==']'||ch=='}'||ch==')'){
        return 1;
    }else{
        return 0;
    }
}
int ifFit(char a,char b){
    if(a=='{'&&b=='}') return 1;
    if(a=='['&&b==']') return 1;
    if(a=='('&&b==')') return 1;
    return 0;
}

int main() {
    vector<char> characters;
    string a;
    cin>>a;
    for (int i = 0; i < a.length(); ++i) {
        if(whatType(a[i])==-1){
            characters.push_back(a[i]);
        }else if(whatType(a[i])==1){
            if(characters.empty()){
              cout<<"false";return 0;
            }else{
                if(ifFit(characters[characters.size()-1],a[i])==0){
                    cout<<"false";return 0;
                }else{
                    characters.pop_back();
                }
            }
        }
    }
    cout<<"true";
    return 0;
}
