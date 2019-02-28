# string

c++ 的string 便于对字符串的操作

## string <=> vector<char> 的互相转换

 
```
// <vector>int => string
vector<char> data;
std::string res;
res.insert(res.begin(), data->begin(), data->end());

string str;
vector <char> ta = {‘a’, 'b', 'c'};
str.clear();
str.assign(ta.begin(),ta.end());

// string => vector<char>, 使用copy函数
string s("122335245");
vector<char> v(s.size());
copy(s.begin(),s.end(),v.begin());
```

# int => string

```
int a = 123;
string s = to_string(a);
```
> to_string()函数可以将int转为string
> 也可以string += 'a';

# 字符串分割函数

在对字符串处理的时候不可避免的遇到了字符串分割问题

1、c语言中的 strtok函数
char *strtok(char *s, const char *delim);
```
#include <stdio.h>
#include <string.h>

int main() {
    char str[30] = "my name is lijj";
    char *p = strtok(str, " ");
    while(p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, " ");
    }
    return 0;
}
```

2、c++中并没有底层实现split函数，而需要自己通过 find, strsub函数获取
```
#include <cstdio>
#include <cstring>
#include <vector> 
#include <iostream>

using namespace std;

vector<string> split(const string &str, const string &dlim) {
    vector<string> res;
    string::size_type pos1 = 0, pos2 = str.find(dlim);
    while(pos2 != string::npos) {
        res.push_back(str.substr(pos1, pos2-pos1));
        pos1 = pos2 + dlim.size();
        pos2 = str.find(dlim, pos1);
    }
    if(pos1 != str.length()) {
        res.push_back(str.substr(pos1));
    }
    return res;
}

int main() {
    vector<string> res = split("my name is lijj", "sd");
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
```