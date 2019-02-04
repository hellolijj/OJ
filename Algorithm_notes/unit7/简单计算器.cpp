// 计算一个 表达式 的值
// 1、搞清楚什么时候表达式的 后缀表达式 中缀表达式 前缀表达式
// 并使用栈来实现它
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>

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


// 设置操作符的优先级
void init_op()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
}


// 将中追表达式 转为 后缀表达式
void change()
{ 
	// string str = "3+4";
	string str = "3+4*5-6/2+3+4+5-4";

	Node temp;
	for (int i = 0; i < str.length(); ++i)
	{
		// 如果是数字
		if (str[i] >= '0' && str[i] <= '9') {
            temp.num = str[i] - '0';
            temp.flag = true;

            // 将数字压入队列
            q.push(temp);
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

int main(int argc, char const *argv[])
{
	
    init_op();
    change();
    print();

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