#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	Node* next;
}Node;

Node* CreateHead(int data) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->next = NULL;

	return temp;
}

void CreateNode(Node* head, int data) {
	while (true)
	{
<<<<<<< HEAD
		if (head->next == NULL)
=======
<<<<<<< HEAD:LinkedList.c
		if(head->next == NULL)
=======
		if (head->next == NULL)
>>>>>>> 2700f9b (Stack):LinkedList.cpp
>>>>>>> master
			break;
		head = head->next;
	}
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	
	head->next = temp;
}

void PrintAllNodes(Node* head) {
	printf("[ ");
	while (head)
	{
		printf("%d", head->data);
		if (head->next)
			printf(", ");
		head = head->next;
	}
	printf(" ]\n");
}

int GetNode(Node* head, int idx) {
	int i = 0;
	while (head)
	{
		if (i == idx) {
			return head->data;
		}
		head = head->next;
		i++;
	}

	return _CRT_INT_MAX;
}

bool InsertNode(Node* head, int data, int idx) {
	int i = 0;
	while (head)
	{
		if (i == idx - 1) {
			if (head->next) {
				Node* temp = (Node*)malloc(sizeof(Node));
				temp->data = data;
				Node* next = head->next;
				head->next = temp;
				temp->next = next;
				return true;
			}
			else {
				CreateNode(head, data);
				return true;
			}
		}
		head = head->next;
		i++;
	}
	return false;
}

bool DeleteNode(Node* head, int idx) {
	int i = 0;
	if (idx < 1) {
		return false;
	}
	else {
		while (head)
		{
			if (i == idx - 1 && head->next->next) {
				Node* temp = head->next->next;
				free(head->next);
				head->next = temp;
				return true;
			}
			else if(i == idx - 1 && !head->next->next) {
				free(head->next);
				head->next = NULL;
				return true;
			}
			head = head->next;
			i++;
		}
	}
	return false;
}

bool ModifyNode(Node* head, int d, int idx) {
	int i = 0;
	if (idx < 0)
		return false;
	while (head) {
		if (idx == i) {
			head->data = d;
			return true;
		}
		head = head->next;
		i++;
	}
	return false;
}

int GetListLength(Node* head) {
	int idx = 0;
	while (true)
	{
		idx++;
		if (head->next == NULL)
			break;
	}
	return idx;
}

void ReverseList(Node* head) {
	Node* p = NULL;
	Node* q = NULL;
	Node* r = NULL;
	p = head;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
}

void DestroyList(Node* head) {
	while (head)
	{
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}

int main() {
	Node* head = CreateHead(1);
	CreateNode(head, 2);
	CreateNode(head, 3);
	CreateNode(head, 4);

	printf("%d\n", DeleteNode(head, 1));
	PrintAllNodes(head);
	
	InsertNode(head, 10, 1);
	PrintAllNodes(head);

	printf("%d\n", GetNode(head, 1));

	printf("%d\n", ModifyNode(head, 100, 0));
	PrintAllNodes(head);
	ReverseList(head);
	PrintAllNodes(head);
	DestroyList(head);
	return 0;
}
