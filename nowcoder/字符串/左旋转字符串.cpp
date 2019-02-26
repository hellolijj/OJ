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
};

int main() {
    class Solution solu;
    cout << solu.LeftRotateString("", 0) << endl;
    return 0;
}

/*

注意边界条件
*/