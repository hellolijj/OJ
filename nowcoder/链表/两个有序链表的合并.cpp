#include <cstdio>

using namespace std;

struct Node{
    int data;
    Node* next;
};

/*
思路一：
普通的遍历

当有一个序列遍历完成后，剩下的另一个序列可通过赋值方法直接实现

思路二:
递归实现
*/

Node* create(int a[], int length) {
    Node *head, *pre;
    head = new(Node);
    pre = head;

    for(int i = 0; i < length; i++) {
        Node *temp = new(Node);
        temp->data = a[i];
        temp->next = NULL;

        pre->next = temp;
        pre = temp;
    }

    return head->next;
}

void print(Node *head) {
    Node *p = head;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

Node* merge(Node* l1, Node* l2) {
    Node *head = new(Node);
    Node* p = head;
    Node *p1 = l1->next, *p2 = l2->next;
    while(p1 != NULL && p2 != NULL) {
        if(p1->data < p2->data) {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
    }
    if(p1 != NULL) {
        p->next = p1;
    }
    if(p2 != NULL) {
        p->next = p2;
    }
    // 也可以通过如下代码实现
    // while(p1 != NULL) {
    //     p->next = p1;
    //     p = p1;
    //     p1 = p1->next;
    // }
    // while(p2 != NULL) {
    //     p->next = p2;
    //     p = p2;
    //     p2 = p2->next;
    // }
    return head;
}

// 递归实现
Node* merge2(Node* l1, Node* l2) {
    if(l1 == NULL) {
        return l2;
    } 
    if(l2 == NULL) {
        return l1;
    }
    if(l1->data < l2->data) {
        l1->next = merge2(l1->next, l2);
        return l1;
    } else {
        l2->next = merge2(l1, l2->next);
        return l2;
    }
    
}

int main() {
    Node *l1, *l2;
    int a[4] = {1, 3, 4, 5};
    int b[5] = {2, 3, 7, 9, 11};
    l1 = create(a, 4);
    l2 = create(b, 5);
    // print(merge(l1, l2));
    print(merge2(l1, l2));
    // print(l1);
}


/*


*/