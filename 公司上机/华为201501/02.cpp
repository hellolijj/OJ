/*题目：

去除重复字符并排序

运行时间限制：无限制

内容限制： 无限制

输入： 字符串

输出： 去除重复字符并排序的字符串

样例输入： aabcdefff

样例输出： abcdef
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void deal() {
    string s;
    cin >> s;
    set<char> st;
    for(int i = 0; i < s.length(); i++) {
        st.insert(s[i]);
    }
    s.assign(st.begin(), st.end());
    cout << s << endl;
}

int main() {

    deal();
    exit(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    vector<char> v;
    // 去重
    // for(int i = 0; s[i] != '\0'; i++) {
    //    if(v.empty()) {
    //        v.push_back(s[i]);
    //    } else {
    //        if(s[i] != v[v.size()-1]) {
    //            v.push_back(s[i]);
    //        }
    //    }
    // }
    // string l;
    // l.assign(v.begin(), v.end());

    for(int i = 1; i < s.length(); i++) {
        if(s[i] == s[i-1]) {
            s.erase(s.begin()+i);
        }
    }
    // cout << s << endl << l << endl;
    cout << s << endl;
    return 0;


}





/*
去重的这一部分需要考虑:
使用vector
使用queue q.font() 表示队首元素，q.end() 表示队尾元素  
queue >> string

记得erase的用法

也可以通过 set 集合来做
*/