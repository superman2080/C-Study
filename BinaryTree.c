#include <stdio.h>
#include <malloc.h>

typedef struct TNode {
	int data;
	TNode* left;
	TNode* right;
}TNode;

TNode* CreateTree(int data) {
	TNode* temp = (TNode*)malloc(sizeof(TNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void AddTree(TNode* head, int data) {

	TNode* temp = (TNode*)malloc(sizeof(TNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	while (head)
	{
		if (data > head->data) {
			if (head->right == NULL)
				head->right = temp;
			else
				head = head->right;
		}
		else if (data < head->data) {
			if (head->left == NULL)
				head->left = temp;
			else
				head = head->left;
		}
		else
			return;
	}
}

void PrintTree(TNode* head, int idx) {
	if (head != NULL) {
		printf("%d Count : %d\n", idx, head->data);
		idx++;
		if (head->left != NULL)
			printf("Left, ");
			PrintTree(head->left, idx);
		if (head->right != NULL)
			printf("Right, ");
			PrintTree(head->right, idx);
	}
}

void DeleteTree(TNode* head) {
	if (head != NULL) {
		if (head->left != NULL) {
			DeleteTree(head->left);
		}
		if (head->right != NULL) {
			DeleteTree(head->right);
		}
		free(head);
		head = NULL;
	}
}

int ExistNode(TNode* head, int data) {
	if (head->data == data) {
		return 1;
	}
	else if (head->data < data && head->right) {
		ExistNode(head->right, data);
	}
	else if (head->data > data && head->left) {
		ExistNode(head->left, data);
	}
	else {
		return 0;
	}

}

int main() {
	TNode* head = CreateTree(10);

	AddTree(head, 5);
	AddTree(head, 15);
	AddTree(head, 7);
	AddTree(head, 6);
	AddTree(head, 9);
	AddTree(head, 12);
	AddTree(head, 17);

	PrintTree(head, 0);

	printf("%d, %d\n", ExistNode(head, 7), ExistNode(head, 18));
	DeleteTree(head);
	
}
