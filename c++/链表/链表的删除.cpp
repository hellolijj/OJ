#include <cstdio>

struct Node {
    int val;
    Node* next;
};


Node* create() {
    int a[5] = {1, 2, 3, 4, 5};
    // int a[5] = {1};
    Node *head = new Node();
    head->val = -1;
    head->next = NULL;

    Node *pre = head;
    for(int i = 0; i < 4; i++) {
        Node* temp = new Node();
        temp->val = a[i];
        temp->next = NULL;

        pre->next = temp;
        pre = temp;
    }

    return head->next;
}

void print(Node *head) {
    Node *p = head;
    while(p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
}

// 第一个元素怎么删除
// 当只有一个元素的时候，删除第一个元素需要有返回值才可以
Node* del(Node* head, int data) {
    
    if(head == NULL) {
        return NULL;
    }

    if(head->val == data) {
        return head->next;
    }

    Node *p = head, *pre = NULL;

    while(p != NULL) {
        if(p->val == data) {
            pre->next = p->next;
            delete(p);
            p = pre->next;
            break;
        } else {
            pre = p;
            p = p->next;
        }
    }
    
    return head;

}
int main() {

    Node *head = create();
    print(head);
    puts("");
    Node *dele = del(head, 1);
    print(dele);

    return 0;
}
