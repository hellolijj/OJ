# queue 类型

## queue 常用函数汇总

q.front();
q.back();
q.empty();
q.pop();

## priority_queue 类型

pq.push(n);
pq.pop();
pq.top(); 获取队首元素

### 对 < 符号的重新定义
```
friend bool operator < (fruit f1, fruit f2) {

}
```