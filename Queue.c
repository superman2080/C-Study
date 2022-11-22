#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	char data;
	Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* reer;
}Queue;

Queue* CreateQueue(char data) {
	Queue* tQ = (Queue*)malloc(sizeof(Queue));
	Node* temp = (Node*)malloc(sizeof(Node));
	tQ->front = temp;
	tQ->reer = temp;
	tQ->front->data = data;
	tQ->front->next = NULL;

	return tQ;
}

void Enqueue(Queue* queue, char data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;


	if (queue->front == NULL) {
		queue->front = temp;
	}
	else {
		queue->reer->next = temp;
	}
	queue->reer = temp;

}

char Dequeue(Queue* queue) {
	if (queue->front != NULL) {
		char res = queue->front->data;
		if (queue->front->next != NULL) {
			Node* next = queue->front->next;
			free(queue->front);
			queue->front = next;
			return res;
		}
		else {
			queue->front = NULL;
			queue->reer = NULL;
			free(queue->front);

			return res;
		}
	}
	return '\n';
}

void PrintQueue(Queue* queue) {
	Node* iter = queue->front;
	while (iter)
	{
		printf("%c", iter->data);
		iter = iter->next;
	}
	printf("\n");
}

void DestroyQueue(Queue* queue) {
	while (queue->front)
	{
		if (queue->front->next != NULL) {
			Node* next = queue->front->next;
			free(queue->front);
			queue->front = next;
		}
		else {
			free(queue->front);
			queue->front = NULL;
			queue->reer = NULL;
			free(queue);
			break;
		}
	}
}


int main() {

	Queue* queue = CreateQueue('A');
	Enqueue(queue, 'B');
	Enqueue(queue, 'C');
	Enqueue(queue, 'D');

	PrintQueue(queue);
	printf("%c\n", Dequeue(queue));
	PrintQueue(queue);
	Enqueue(queue, 'Q');
	printf("%c\n", Dequeue(queue));	
	printf("%c\n", Dequeue(queue));
	printf("%c\n", Dequeue(queue));
	printf("%c\n", Dequeue(queue));
	DestroyQueue(queue);


	return 0;
}