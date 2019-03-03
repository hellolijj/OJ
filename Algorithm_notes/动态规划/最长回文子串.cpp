#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

string s;

// 判断一个字符串是否是回文字符串
bool is_huiwen(int left, int right) {

    if(left == right) {
        return true;
    }
    if(left + 1 == right) {
        return s[left] == s[right];
    }
    if(s[left] != s[right]) {
        return false;
    }

    return is_huiwen(left+1, right-1);
}


// 求最长回文序列

int main() {

    string str = "AATZJUJZT";
    vector<vector<int> >d(str.length(), vector<int>(str.length(), 0));
    int res = 1;

    // 初始化
    for(int i = 0; i < d.size(); i++) {
        d[i][i] = 1;
        for(int j = 1; j < d.size()-1; j++) {
            if(str[i] == str[i+1]) {
                d[i][i+1] = 1;
                res = 2;
            }
        }
    }

    // 动态规划
    for(int l = 3; l <= str.length(); l++) {  // l表示长度
        for(int i = 0; i < str.length() - l + 1; i++) {     // 从0开始对后面的字符串进行遍历
            int j = i+l-1;    // j表示右侧
            if(d[i+1][j-1] == 1 && str[i] == str[j]) {
                d[i][j] = 1;
                res = l;
            }
        }
    }


    for(int i = 0; i < d.size(); i++) {
        for(int j = 0; j < d[i].size(); j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", res);
    return 0;
}