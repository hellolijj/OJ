/*题目描述
输入两个链表，找出它们的第一个公共结点。

思路：如源代码

注意点：p1 == p2 表示 p1及p1后面的内容均与p2相同


*/

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL){
            return NULL;
        }
        int l1 = 0, l2 = 0;
        ListNode *p1 = pHead1, *p2 = pHead2;
        while(p1 != NULL) {
            l1 ++;
            p1 = p1->next;
        }
        while(p2 != NULL) {
            l2 ++;
            p2 = p2->next;
        }
        int diff;
        if(l1 > l2) {
            diff = l1 - l2;
            p1 = pHead1;
            p2 = pHead2;
        } else {
            diff = l2 - l1;
            p1 = pHead2;
            p2 = pHead1;
        }
        // p1 指向长的
        for(int i = 0; i < diff; i++){
            p1 = p1->next;
        }
        while(p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};