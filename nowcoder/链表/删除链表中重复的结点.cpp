/*题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/*
testcase
1->2->3->3->4->4->5 处理后为 1->2->5
*/

/*
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        // 0节点
        if(pHead == NULL) {
            return NULL;
        }
        // 1个节点
        if(pHead->next == NULL) {
            return pHead;
        }

        // 2个及2个以上的节点
        ListNode *head = pHead, *p1 = pHead, *p2 = pHead->next;
        
        while(p2 != NULL) {
            int a = p1->val;
            int b = p2->val;
            if(a == b) {
                // 删除两个节点指针
                head = p2->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return head;
    }
};

*/

#include <cstdio>
// #include <cstdio>

struct Node {
    int val;
    Node* next;
};


Node* create() {
    int a[6] = {1, 1, 2, 3, 4, 5};
    // int a[5] = {1};
    Node *head = new Node();
    head->val = -1;
    head->next = NULL;

    Node *pre = head;
    for(int i = 0; i < 6; i++) {
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

// 删除重复的元素
Node* deleteDuplication(Node *head) {

    if(head == NULL) {
        return NULL;
    }

    Node *p = head, *pre = NULL, *q = NULL;  // p表示当前节点、pre表示当前节点的前一个节点、q表示 有相同值时候的最后一个节点

    while(p != NULL) {
        
        //当前结点p，（其实是p指向当前结点），与它下一个结点p->next的val相同，说明要删掉有这个val的所有结点
        if(p->next != NULL && p->val == p->next->val) {
            
            //找到q，它指向最后一个与p val相同的结点，那p 到 q （包含） 都是要删除的
            q = p->next;
            while(q != NULL && q->next != NULL && q->next->val == p->val) {
                q = q->next;
            }
            // 此时 q指向最后一个同p相同的指针

            //如果p指向链表中第一个元素，p -> ... -> q ->... , 要删除p到q, 将指向链表第一个元素的指针pHead指向q->next
            if(p == head) {
                head = q->next;
            } else {
                // 如果p不指向链表中第一个元素，pre -> p ->...->q ->... ，要删除p到q，即pre->next = q->next
                pre->next = q->next;
            }
            p = q->next;
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
    
    
    Node *dup = deleteDuplication(head);
    print(dup);

    return 0;
}
