/*题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

// 思路：1、复制链表使之连接起来2、同步的随机指针 3、拆分表

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

#include <cstdio>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        // 复制一个个节点，使连成一个串
        if (pHead == NULL) {
            return NULL;
        }
        RandomListNode *current_node = pHead;
        while(current_node) {
            RandomListNode *node = new RandomListNode(current_node->label);
            node->next = current_node->next;
            current_node->next = node;
            current_node = node->next;
        }

        // 同步rand指针
        current_node = pHead;
        while(current_node) {
            RandomListNode *next_node = current_node->next;
            if(current_node->random) {
                next_node->random = current_node->random->next;
            }
            current_node = next_node->next;
        }

        // 拆分表
        RandomListNode *clone_head = pHead->next;
        current_node = pHead;
        RandomListNode *temp;
        
        // 这个拆表的注意点，因为要保证所有的复制节点都能节点
        while(current_node->next) {
            temp = current_node->next;
            current_node->next = temp->next;
            current_node = temp;
        }
        return clone_head;
    }
};
/*

while(current_node) {
    temp = current_node->next;
    current_node->next = temp->next;
    current_node = temp->next;
}
*/

int main() {
    return 0;
}