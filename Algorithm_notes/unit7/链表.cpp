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

int main(int argc, char const *argv[])
{
	int a[10] = {2, 3, 4, 5, 6, 8, 9, 0, 1, 7};
	
	print(create(a, 10));
	
	return 0;
}

// 总结：
// 没创建一个节点，节点的 p->next = NULL