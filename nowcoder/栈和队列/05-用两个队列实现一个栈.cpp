#include <stack>
#include <queue>

using namespace std;

/*
2个队列模拟1个栈
2个栈模拟一个队列
都是1个进1个出，按照各自的特性正常操作

2个栈模拟1个队列
如果stack2不为空，直接取stack.top()
如果stack2为空，将所有的stack1 出栈 ，进栈到queue2

2个队列模拟一个栈
如果 queue1元素只有1个，直接取 queue2.front();
如果 queue1元素有0个，直接取 -1;
如果 queue1元素有多个，queue1出队 ，进队到queue2。直到 queue1.size() == 1
取出 那个值，再将所有的queue2元素 出队， 进队到queue1
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()) {
            // stack1 => stack2
            while(!stack1.empty()){
                int temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
        }

        int n = stack2.top();
        stack2.pop();
        return n;
    }

    void push_back(int node) {
        queue1.push(node);
    }

    int top() {

        int res;

        if(queue1.empty()) {
            return -1;
        }
        
        while(queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        res = queue1.front();
        queue1.pop();

        // 将queue2 => queue1
        while(!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }

        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;

    queue<int> queue1;
    queue<int> queue2;
};

int main() {
    class Solution solu;
    solu.push(2);
    solu.push(3);
    printf("%d\n", solu.pop());
    printf("%d\n", solu.pop());
    
    solu.push(4);
    solu.push(5);
    printf("%d\n", solu.pop());
    solu.push(6);
    printf("%d\n", solu.pop());
    printf("%d\n", solu.pop());

    printf("**********\n");
    solu.push_back(1);
    solu.push_back(2);
    solu.push_back(3);
    printf("%d\n", solu.top());
    solu.push_back(1);
    printf("%d\n", solu.top());
    return 0;
}