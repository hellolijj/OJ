#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 101;

int max_length(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int res = 0;  // 记录最大的公共字串长度
    vector<vector<int> > v(len1+1, vector<int>(len2+1));
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0 || j == 0) {
                v[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                v[i][j] = v[i-1][j-1] + 1;
                res = max(v[i][j], res);  
            } else {
                v[i][j] = 0;
            }
        }
    }
    return res;
}

int main() {

    string str1 = "sdfagdasgasdgas";
    string str2 = "sdfadgdasgasd";

    cout << max_length(str1, str2) << endl;
    return 0;
}