/*题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
思路：
方法一：使用栈，进栈出栈
我一开始想的办法。需要掌握到链表的重新创建

方法二：递归
void reverse(link a) {
    // 出口
    if(a.length == 0 || a.length == 1) {
        return a[0];
    }

    // 反转
    node b = reverse(a[1]);
    // 将第一个元素接到第二个节点的后面
    move_to_end(a[0], b);
}

方法三：指针反转
这种方法确实很难，画了很多遍也无法理解。先放一放
https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca
*/

#include <cstdio>
#include <stack>

using namespace std;

struct Node{
    int data;
    Node* next;
};



class Solution {
public:
    Node* ReverseList(Node* pHead) {
        stack<int> s;
        Node *p = pHead;
        
        // 进栈
        while(p != NULL) {
            s.push(p->data);
            p = p->next;
        }
        
        // 出栈
        Node *head = new Node();
        Node *pre = head;
        while(!s.empty()){
            Node *temp = new Node();
            temp->data = s.top();
            temp->next = NULL;
            s.pop();
            
            pre->next = temp;
            pre = temp;
        }
        
        return head->next;
    }

    // 递归
    Node* ReverseList1(Node* pHead) {
        
        if(pHead == NULL || pHead->next == NULL) {
            return pHead;
        }

        Node *new_head = ReverseList1(pHead->next);


        pHead->next->next = pHead;
        pHead->next = NULL;

        return new_head;
    }
};

/*
使用递归的反转链表结尾部分有些不太会掌握
*/


Node* create(int a[], int length) {

    Node *head = new Node;
    Node *p = head;
    
    for(int i = 0; i < length; i++) {
        Node *temp = new(Node);
        temp->data = a[i];
        temp->next = NULL;

        // 再将当前节点设置为后面节点的后续节点
        // 这是难点
        p->next = temp;
        p = temp;
    }
    
    return head->next;
}

void print(Node* head) {
    Node *p = head;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}



int main() {
    Node *head;
    int b[5] = {2, 3, 7, 9, 11};
    head = create(b, 5);
    print(head);
    class Solution solu;
    Node *reverse_head = solu.ReverseList1(head);
    print(reverse_head);
}