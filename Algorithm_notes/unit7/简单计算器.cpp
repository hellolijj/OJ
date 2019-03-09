// 计算一个 表达式 的值
// 1、搞清楚什么时候表达式的 后缀表达式 中缀表达式 前缀表达式
// 并使用栈来实现它
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

struct Node
{
	char op;
	int num;
	bool flag;    // flag true 表示 操作数字  false 表示操作符
};

queue<Node> q;  // 后缀表达式队列
stack<Node> s;  // 操作符栈
map<char, int> op;    // 操作符

string str;


// 设置操作符的优先级
void init_op()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
}


// 将中缀表达式 转为 后缀表达式
void change()
{ 
	// string str = "3+4";
	// string str = "3+4*5-6/2+3+4+5-4";

	Node temp;
	int t = 0;   // t 用于处理 (string)123  => int(123)
	for (int i = 0; i < str.length(); ++i)
	{
		// 如果是数字
		if (str[i] >= '0' && str[i] <= '9') {
            temp.num = t * 10 + str[i] - '0';
            temp.flag = true;

            // 将数字压入队列
            q.push(temp);
			t = temp.num;
        } else {
        	// 如果当前操作符op优先级 <= 队列首操作符，
        	// 则将队首操作符压出并排入到后缀表达式中
        	while(!s.empty() && op[str[i]] <= op[s.top().op]) {
        		q.push(s.top());
        		s.pop();
        	}

        	// 把该操作符压入到操作符队列中
        	temp.op = str[i];
        	temp.flag = false;
        	s.push(temp);
        	t = 0;
        }    
	}

	// 将操作队列里所有操作符压出 到 队列中
    while(!s.empty()) {
    	q.push(s.top());
    	s.pop();
    }
}


void print() {

	Node temp;

	while(!q.empty()) {
		temp = q.front();
		if (temp.flag)
		{
			printf("%d", temp.num);
		} else {
			printf("%c", temp.op);	
		}
		
		q.pop();
	}

}

// 计算后缀表达式
int cal() {

	Node temp, cur;
	while(!q.empty()) {
		cur = q.front();
		q.pop();

		// 如果是数字
		if (cur.flag){
			s.push(cur);
		} else {
			Node num2 = s.top(); s.pop();
			Node num1 = s.top(); s.pop();
			temp.flag = true;

			switch(cur.op) {
				case '+': temp.num = num1.num + num2.num; break;
				case '-': temp.num = num1.num - num2.num; break;
				case '*': temp.num = num1.num * num2.num; break;
				case '/': temp.num = num1.num / num2.num; break;
			}
			s.push(temp);
		}
	}

	return s.top().num;
}

int main(int argc, char const *argv[])
{
	
    init_op();
	// getline 输入法，获取输入的一行内容
	while(getline(cin, str), str != "0") {
		
		// 消除没有用的空格
		for(string::iterator it = str.begin(); it != str.end(); it++) {
			if(*it == ' ') {
				str.erase(it);
			}
		}

		// 初始化栈
		while(!s.empty()) s.pop();
		// 初始化队列
		while(!q.empty()) q.pop();
		change();	
		printf("%d\n", cal());
	}
    
    // print();
    

	return 0;
}

/*
中缀表达式： 运算符放在两个运算对象中间。如： 1+2  (1+2) * 3
后缀表达式： 不包含括号，运算符放在两个运算对象后面。所有的运算按照运算符出现的顺序，严格从左向右进行（不考虑运算符的优先规则）
eg: 2 1 + 3 *
前缀表达式： 同后缀表达式一样，不包括括号，运算符放在两个运算对象前面。 如： * + 2 1 3
*/

/*
表达式的转换
中缀表达式 => 后缀表达式

1、建立一个操作符栈，用于存放临时操作符；设立一个数组或者队列用于存放后缀表达式
2、从左至右扫描中缀表达式。遇到操作数则放在后缀表达式中。遇到操作符
	1）如果遇到操作符则与操作符栈栈顶操作符比较
	2）如果操作符高于栈顶操作符，则压入操作符栈
	3）如果操作符低于或者等于栈顶操作符的优先级，
	则将操作符栈的操作符不断的弹出到后缀表达式中
	直到该操作符高于栈顶操作符。
	4）如果将该操作符op压入栈中。
不断重复以上过程，直到遍历完所有的中缀表达式。然后将操作符栈的符号压入到后缀表达式中。
*/

/*
后缀表达式的计算
1、将后缀表达式队列从左至右依次压入到栈中
2、如果遇到操作数，则将数字压入到栈中。
3、如果遇到操作符，则弹出两个操作数。先弹出的位第二操作数，后弹出的位第一操作数。与运算符进行计算
将计算结果再压入到栈中。
*/

/*
如何处理字符串中的123 转为 123？

设置一个int temp 变量？

int t = 0;
for() {
	if(is_num) {
		n = t * 10 + s[i];
	} else {
		t = 0;
	}
}


*/

/*
如何获取 每一行string

*/


