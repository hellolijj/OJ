/*
第一题(60分)：
​按要求分解字符串，输入两个数M，N；M代表输入的M串字符串，N代表输出的每串字符串的位数，不够补0。
例如：输入2,8， “abc” ，“123456789”，则输出为“abc00000”,“12345678“,”90000000”
*/

//思路：递归

#include<iostream>
#include<string>
using namespace std;
void dfs(string a,int n) {
	if (a.length() <= n) { //如果字符串长度不够，补0，直接输出
		cout << a;
		for (int i = 0; i < n - a.length(); i++) { 
			cout << '0';
		}
		cout << endl;
	}
	else { // 长度超出，截断字符串
		cout << a.substr(0, n) << endl;
		dfs(a.substr(n), n);  //递归字符串其余的内容
	}
}
int main() {
	int m,n; 
	cin >> m >> n;
	string a;//输入的字符串
	for (int i = 0; i < m; i++) {
		cin >> a;
		dfs(a,n); //递归
	}
}

// 这个题目为什么要dfs呢？ 好想使用while循环也是可以的实现