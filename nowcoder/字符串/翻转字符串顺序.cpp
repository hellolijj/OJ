/*
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

*/
#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.length() == 0) {
            return "";
        }
        stack<string > s;
        string temp;
        for(int i = 0; str[i] != '\0'; i++) {
            if(str[i] != ' ') {
                temp += str[i];
            } else {
                s.push(temp);
                temp = "";
            }
        }
        s.push(temp);
        temp = "";

        string res;
        
        while(!s.empty()) {
            string t = s.top();
            res += t;
            res += " ";
            s.pop();
        }
        res.erase(res.end());
        return res;
    }
};

int main() {

    class Solution solu;
    cout << solu.ReverseSentence("sdfa is adfja;fa sdf.") << endl;
    return 0;
}