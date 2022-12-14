#include <stdio.h>

//���� ����
//�ð� ���⵵ : O(n^2) (Worst of worst)
void BubbleSort(int arr[], int arrSize) {
	for (int i = arrSize - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
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
		min = i;
		for (int j = i; j < arrSize; j++)
		{
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

//���� ����
//�ð� ���⵵: O(n^2) 
//n^2�� �ð� ���⵵�� ���� ���� �� ���� ����
void InsertionSort(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
		{
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}

}

int main() {
	int arr[5] = { 5, 1, 9, 2, 7 };
	int arrSize = sizeof(arr) / sizeof(int);
	InsertionSort(arr, arrSize);

	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}