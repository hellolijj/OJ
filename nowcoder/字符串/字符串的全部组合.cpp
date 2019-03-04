#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
求n个数字的组合
思路：
针对第一个字符，我们有两种选择：
第一是把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符；
第二是不把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选择m个字符。
*/



class Solution {

public:
    vector<string> res;
    
    vector<string> Permutation(string str) {
        if(str.length() == 0) {
            return res;
        }
        vector<char> r;
        Permutation1(str, 0, r);
        sort(res.begin(), res.end());
        return res;
    }
    
    void Permutation1(string s, int begin, vector<char> &r) {
        if(begin == s.length()) {
            string str;
            str.assign(r.begin(), r.end());
            // 排除全部不存在情况
            if(!r.empty()) {
                res.push_back(str);
            }
            return;
        }
        
        

        // begin这个字符放进去
        r.push_back(s[begin]);
        Permutation1(s, begin+1, r);

        // begin这个字符不放进去
        r.pop_back();
        Permutation1(s, begin+1, r);

        
    }
};

int main() {
    class Solution solu;
    solu.Permutation("abc");
    sort(solu.res.begin(), solu.res.end());
    for(int i = 0; i < solu.res.size(); i++) {
        cout << solu.res[i] << endl;
    } 
    return 0;
}

/*
总结：好像一定要这种顺序，
先将这个元素压入到 vector<char> 里
再将这个元素pop_back出来
*/