/*题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

testcase "abc", "a", "aaa", "abcdd"

思路，整个题目分为两个步骤
步骤一：将字符串分为两个部分{第一个字母，剩下的部分}
步骤二：写递归函数，处理 p(first_char, next_str);
注意：还有重复字符串的情况

方法：递归方法
回朔方法

*/
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
    vector<string> result;
    vector<string> Permutation(string str) {
        if(str.length()==0){
            return result;
        }
        Permutation1(str,0);
        sort(result.begin(),result.end());
        return result;
    }
    void Permutation1(string str,int begin){
        if(begin == str.length()){
            result.push_back(str);
            return ;
        }
        for(int i = begin; str[i]!='\0';i++){
            if(i!=begin&&str[begin]==str[i])   // 存在相同的情况， 如abcc
                continue;
            swap(str[begin],str[i+1]);
            Permutation1(str,begin+1);
            swap(str[begin],str[i+1]);
        }
    }
};

int main() {
    class Solution solu;
    solu.Permutation("abcc");
    for(int i = 0; i < solu.result.size(); i++) {
        cout << solu.result[i] << endl;
    } 
    return 0;
}