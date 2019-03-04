# 字符串问题

## 字符串的排序
student am i => i am student

## 字符串的移动

str + str 然后再去 start, end

## 字符串的全部组合
```
p(string str, int begin, vector<char> &v) {
    if(begin == str.length) {
        排除 v 为 null情况
        v => string  =>res;
        // string.assign(v.begin(), b.end());
        res.push(string)
    }

    v.push(str[begin]);
    p(str, begin+1, v);

    v.pop_back();
    p(str, begin+1, v);
}
```

## 字符串到全部排列

```
p(string str, int begin) {
    if(begin == str.length()) {
        temp => res;
        return;
    }
    for(i:0=>length-1) {
        if(i != begin && str[i] != str[begin]) {
            swap(str[i], str[begin]);
            p(str, begin+1)
            swap(str[begin], str[i]);
        }
    }
}

str 调用这个函数
p("abc", 0);
```

