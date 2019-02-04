#include <cstdio>

struct Node
{
	int data;
	Node* next;
};

Node* create(int a[], int len) {

	Node *head, *pre, *p;

	head = new Node;
	head->next = NULL;

	pre = head;
	for (int i = 0; i < len; ++i)		
	{
		p = new Node;
		p->data = a[i];
		p->next = NULL;

		pre->next = p;
		pre = p;
	}
	return head;
}

void print(Node *head) {

	Node* L = head -> next;

	while(L != NULL) {
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");

}

// 在链表中查找，统计x元素的个数
int count(Node *head, int x) {

	int cnt = 0;

	Node *L = head->next;

	while(L != NULL) {
		if(L->data == x) {
			cnt ++;
		}
		L = L->next;
	}

	return cnt;
}

// 在pos处插入一个元素
void insert(Node *head, int pos, int x) {

	Node *L = head;

	for(int i = 0; i < pos; i++) {
		L = L->next;
	}
	// 创建一个节点
	Node *p = new Node;
	p->data = x;

	// 链接节点
	p->next = L->next;
	L->next = p;
}

// 删除元素
void del(Node *head, int x) {

	Node *L = head->next;
	Node *pre = head;     // pre始终保持p的前驱节点

	while(L != NULL) {
		if(L->data == x) {
			pre->next = L->next;
			delete(L);
			L = pre->next;
		} else {
			L = L->next;
			pre = pre->next;
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[10] = {2, 3, 4, 4, 6, 4, 9, 0, 1, 7};
	
	Node *head = create(a, 10);
	print(head);

	printf("元素4的个数: %d\n",count(head, 4));

	insert(head, 2, 100);
	print(head);

	del(head, 100);
	print(head);
	
	return 0;
}

// 总结：
// 每y创建一个节点，节点的 p->next = NULL