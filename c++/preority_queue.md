# preority_queue 优先级队列

## 使用

1、引用头文件

#include <queue>

2、怎么插入

定义
```
priority_queue<int> q;
q.push(69);
int a = q.top();


```
3、自定义排序

stuct fruit {
    string name;
    int price;
    friend bool operator < (fruit f1, fruit f2) {
        return f1.price < f2.price;
    }
}

> 自定义 priority_queue<>

