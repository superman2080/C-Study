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
	while (head->next)
	{
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

bool AddNode(Node* head, int data, int idx) {
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

	if (idx == 0) {
		Node* temp = head;
		temp = temp->next;
		free(head);
		return true;
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

	DeleteNode(head, 2);
	
	AddNode(head, 10, 2);
	PrintAllNodes(head);

	printf("%d\n", GetNode(head, 0));

	DestroyList(head);
	return 0;
}