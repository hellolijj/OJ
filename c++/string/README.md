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