/* 思路
链表第长度n
取出第(n-k)个节点，顺序输出 
这是不对的

k是一把尺子不对下移尺子直到尺子的尾巴与可比物相同，那个就找到了k的那个节点
https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a
*/ 
#include <cstdio>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* create(int a[], int length) {

    Node *head = new Node;
    Node *p = head;
    
    for(int i = 0; i < length; i++) {
        Node *temp = new(Node);
        temp->data = a[i];
        temp->next = NULL;

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

Node* d_create(Node *head, int k) {
    // todo k非法判断
    if (k == 0) {
        return NULL;
    }

    Node *p = head, *pre = head;
    for(int i = 0; i < k; i++) {
        if(p == NULL) {
            return NULL;
        }
        p = p->next;
    }

    while(p != NULL) {
        pre = pre->next;
        p = p->next;
    }
    return pre;
}

int main() {
    Node *head;
    int b[5] = {2, 3, 7, 9, 11};
    head = create(b, 5);
    Node *d_head = d_create(head, 6);
    print(head);
    print(d_head);
}

/* 考虑k的集中特殊情况

链表长度为n
k = 0
k = n
k > n; 按照题目的意思要输出 NULL
*/