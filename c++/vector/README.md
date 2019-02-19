# vector

> vector 是向量，也是容器，也是动态数组。

## 基本构造函数

```
// 创建一个空vector
vector()
// 创建一个空 vector 元素为n个
vector(n)
// 创建一个空 vector 元素为n个 且初始化值都为m
vector(n,m)
// 还可以将一个vector 复制给另一个vector
```

## vector 遍历

## vector 基本操作

## vector 拷贝

1、vector创建时候的拷贝
```
vector<int> a(5, 1);
vector<int> b(a);
```
2、循环赋值拷贝

3、assgin赋值拷贝
```
vector<int> a(5, 1);
vector<int> b;
b.assign(a.begin(), a.end())
```
> assgin是深拷贝，分配了新的内存空间
4、使用swap赋值
```
vector<int> a(5, 1);
vector<int> b;
b.swap(a);
```
> swap不仅是浅拷贝，而且之间的vector<int> a也失去内容了