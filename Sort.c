#include <stdio.h>

//버블 정렬
//시간 복잡도 : O(n^2) (Worst of worst)
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

//선택 정렬
//시간 복잡도 : O(n^2)
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

//삽입 정렬
//시간 복잡도: O(n^2) 
//n^2의 시간 복잡도를 갖는 정렬 중 가장 빠름
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