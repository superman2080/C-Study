#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	Node* next;
}Node;

typedef struct Stack {
	Node* top;
}Stack;

Stack* CreateStack(int data) {
	Stack* tS = (Stack*)malloc(sizeof(Stack));
	Node* temp = (Node*)malloc(sizeof(Node));
	tS->top = temp;
	tS->top->data = data;
	tS->top->next = NULL;
	return tS;
}

bool IsEmpty(Stack* stack) {
	return stack->top == NULL;
}

void Push(Stack* stack, int data) {

	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;

	if (stack->top == NULL) {
		temp->next = NULL;
	}
	else {
		Node* topPtr = stack->top;
		temp->next = topPtr;
	}
	stack->top = temp;
}

int Pop(Stack* stack) {
	int data = stack->top->data;
	Node* topPtr = stack->top->next;
	free(stack->top);
	stack->top = topPtr;
	return data;
}

int Peak(Stack* stack) {
	return stack->top->data;
}

int main() {
	Stack* stack = CreateStack(1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);

	printf("isEmpty : %d\n", IsEmpty(stack));

	printf("%d\n", Peak(stack));
	while (stack->top)
	{
		printf("%d\n", Pop(stack));
	}
	printf("isEmpty : %d\n", IsEmpty(stack));

	return 0;
}