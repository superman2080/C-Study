#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	char data;
	Node* next;
}Node;

typedef struct Stack {
	Node* top;
}Stack;

Stack* CreateStack(char data) {
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

void Push(Stack* stack, char data) {

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

void PrintStack(Stack* stack) {
	Node* temp = stack->top;
	printf("[");
	while (temp)
	{
		printf(" %c ", temp->data);
		temp = temp->next;
	}
	printf("]\n");
}

int Peak(Stack* stack) {
	return stack->top->data;
}

void DestroyStack(Stack* stack) {
	while (stack->top != NULL)
	{
		if (stack->top->next != NULL) {
			Node* next = stack->top->next;
			free(stack->top);
			stack->top = next;
		}
		else {
			free(stack->top);
			free(stack);
		}
	}
}

int main() {
	Stack* stack = CreateStack('A');
	Push(stack, 'B');
	printf("%c\n", Pop(stack));
	Push(stack, 'C');
	Push(stack, 'D');

	printf("isEmpty : %d\n", IsEmpty(stack));

	printf("%c\n", Peak(stack));
	PrintStack(stack);
	while (stack->top)
	{
		printf("%c\n", Pop(stack));
	}
	printf("isEmpty : %d\n", IsEmpty(stack));
	Push(stack, 'S');
	DestroyStack(stack);
	return 0;
}