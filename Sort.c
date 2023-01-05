#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//���� ����
//�ð� ���⵵ : O(n^2) (Worst of worst)
void BubbleSort(int arr[], int arrSize) {
	for (int i = arrSize - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//���� ����
//�ð� ���⵵ : O(n^2)
void SelectionSort(int arr[], int arrSize) {
	int min = 0;
	for (int i = 0; i < arrSize; i++)
	{
		//�켱 ���� ���� �ε����� ����
		min = i;
		for (int j = i; j < arrSize; j++)
		{
			//�ε������� j���� ũ�� �ε����� j�� �ٲ�
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		//�ε����� j�� ���� �ٲ�
		Swap(&arr[min], &arr[i]);
	}
}

//���� ����
//�ð� ���⵵: O(n^2) 
//n^2�� �ð� ���⵵�� ���� ���� �� ���� ����
void InsertionSort(int arr[], int arrSize) {
	//�տ��� �ڷ� ��ȸ
	for (int i = 0; i < arrSize; i++)
	{
		//i�������� ������ ��ȸ, ���� j�� j + 1���� ������ ��ȸ�� ����
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
		{
			Swap(&arr[j], &arr[j + 1]);
		}
	}

}


//������
//�ð� ���⵵: O(nlogn)
//��κ��� ��Ȳ���� ���� ���� ����
//�߰� �޸𸮸� ��� X
//�־��� ��Ȳ���� ���� �ð� ���⵵�� ���� ���� �� �־� (n^2)
void QuickSort(int arr[], int left, int right) {
	//�߾��� �ε����� pivot�� ����
	int pivot = (left + right) / 2;
	//���ȣ�⿡ ���� ���� left�� right���� ����
	int nextL = left, nextR = right;

	do {
		//�ǹ����� ū arr[left]���� Ž��...
		while (arr[left] < arr[pivot])
			left++;
		
		//�ǹ����� ū arr[right]���� Ž��...
		while (arr[right] > arr[pivot])
			right--;
		
		//left�� right���� ���� �� (�ǹ����� ū ���� ����, �ǹ����� ���� ���� �����ʿ� ���� ��)
		if (left <= right) {
			//�� ���� �ٲٰ� left�� right�� �����ϰ� �ϱ� ���� ����
			Swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	} while (left <= right);

	//right�� ������ left������ Ŭ ��� (�迭�� ������ ������ ���� ���)
	if (nextL < right)
		QuickSort(arr, nextL, right);

	//���� ����
	if (left < nextR)
		QuickSort(arr, left, nextR);
}



int main() {
	srand(time(NULL));
	int arr[1000] = { 0, };
	int arrSize = sizeof(arr) / sizeof(int);
	for (int i = 0; i < arrSize; i++)
	{
		bool notEqual = true;
		int temp = 0;

		while (true)
		{
			notEqual = true;
			temp = rand() % 1000 + 1;
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					notEqual = false;
					break;
				}
			}
			if (notEqual == true)
				break;
		}
		arr[i] = temp;
	}
	double start, end;
	start = (((double)clock()) / CLOCKS_PER_SEC);
	//BubbleSort(arr, arrSize );
	//SelectionSort(arr, arrSize);
	//InsertionSort(arr, arrSize);
	QuickSort(arr, 0, arrSize - 1);
	end = (((double)clock()) / CLOCKS_PER_SEC);

	for (int i = 0; i < arrSize; i++)
	{
		printf("%d\t ", arr[i]);
	}
	printf("\n���� ���� �ð� : %lf", (end - start));


	return 0;
}