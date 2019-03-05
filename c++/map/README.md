# MAP

> map 是用于建立一种映射关系，通常用于字符 => 整数、字符串 => 整数

## 基本操作

### map的定义

```
// map 的定义
map<char, int> mp;
map<string, int> mp1;
map<set<int>, int> mp2;

// map 的访问
map['a'] = 2;

// map 的遍历
for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    printf("%c %d", it->first, it->second);
}
```
> map 会按照键从小到大的顺序自动排序，内部使用红黑树实现。也不同通过sort函数排序

### 如何实现map的排序？map 通常与 pair组合使用

```
#include <utility>

// pair的定义
pair<char, int> p;
p->first = 'a';
p->second = 1;

// pair可以用来比较大小，先比较fisrt的值，再比较second的值
if(p1 == p2) 
    printf(p1->first, p1->second);

// 常见如下

map<string, int> mp;
mp.insert(make_pair("lijj", 4));
mp.insert(pair<string, int>("lijj", 4));

```

## map 函数汇总

mp.find(key) 返回的是一个it类型
通过 it->first, it->second 来访问map的key 和 value
mp.erase(it);
mp.erase(it_first, it_last);
mp.size();