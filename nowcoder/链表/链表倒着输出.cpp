#include <cstdio>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) :
    //     val(x), next(NULL) {
    // }
};

/*
思路：顺序输出链表到一个vector里，然后对vector进行反转。
反转可以使用栈实现，也使用两个vector，也可以使用

*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {

    	ListNode* p = head->next;
        vector<int> a;

    	while(p != NULL) {
    		a.push_back(p->val);
            p = p->next;
    	}

        return vector<int>(a.rbegin(), a.rend());
        
    }

    ListNode* create(vector<int> v) {
        ListNode *head, *pre;
        head = new ListNode();
        head->next = NULL;     // 第一个节点就是head
        pre = head;

        for(int i = 0; i < v.size(); i++) {
            ListNode* p = new ListNode;
            p->val = v[i];
            p->next = NULL;

            pre->next = p;
            pre = p;
        }

        return head;
    }
};

int main() {

	vector<int> vi(5, 2);
    class Solution Solu;
    ListNode* head = Solu.create(vi);
    vector<int> res = Solu.printListFromTailToHead(head);

    for(int i = 0; i < res.size(); i++) {
        printf("%d", res[i]);
    }
    
    
    return 0;
}

/*
链表的遍历
有时候 p = head->next
有时候 p = head;
很烦无法确定下来:

注意⚠️： 牛客网环境与本地环境的区别

结构体的定义：
结构体的定义要按照现在这个版本来，没有构造函数

结构体的创建。
在本地创建5个元素的链表需要6个节点，头节点也是一个节点
但是牛客网5个元素的链表就是5个节点不知道 它是怎么做到的
*/