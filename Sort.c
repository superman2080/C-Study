#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//버블 정렬
//시간 복잡도 : O(n^2) (Worst of worst)
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

//선택 정렬
//시간 복잡도 : O(n^2)
void SelectionSort(int arr[], int arrSize) {
	int min = 0;
	for (int i = 0; i < arrSize; i++)
	{
		//우선 가장 앞의 인덱스를 가짐
		min = i;
		for (int j = i; j < arrSize; j++)
		{
			//인덱스값이 j보다 크면 인덱스를 j로 바꿈
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		//인덱스와 j의 값을 바꿈
		Swap(&arr[min], &arr[i]);
	}
}

//삽입 정렬
//시간 복잡도: O(n^2) 
//n^2의 시간 복잡도를 갖는 정렬 중 가장 빠름
void InsertionSort(int arr[], int arrSize) {
	//앞에서 뒤로 순회
	for (int i = 0; i < arrSize; i++)
	{
		//i에서부터 앞으로 순회, 만약 j가 j + 1보다 작으면 순회를 멈춤
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
		{
			Swap(&arr[j], &arr[j + 1]);
		}
	}

}


//퀵정렬
//시간 복잡도: O(nlogn)
//대부분의 상황에서 가장 빠른 정렬
//추가 메모리를 사용 X
//최악의 상황에선 같은 시간 복잡도를 갖는 정렬 중 최악 (n^2)
void QuickSort(int arr[], int left, int right) {
	//중앙의 인덱스를 pivot에 저장
	int pivot = (left + right) / 2;
	//재귀호출에 써줄 기존 left와 right값을 저장
	int nextL = left, nextR = right;

	do {
		//피벗보다 큰 arr[left]값을 탐색...
		while (arr[left] < arr[pivot])
			left++;
		
		//피벗보다 큰 arr[right]값을 탐색...
		while (arr[right] > arr[pivot])
			right--;
		
		//left가 right보다 작을 때 (피벗보다 큰 값이 왼쪽, 피벗보다 작은 값이 오른쪽에 있을 때)
		if (left <= right) {
			//두 값을 바꾸고 left와 right가 교차하게 하기 위해 증감
			Swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	} while (left <= right);

	//right가 기존의 left값보다 클 경우 (배열의 분할이 끝나지 않은 경우)
	if (nextL < right)
		QuickSort(arr, nextL, right);

	//위와 동일
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
	printf("\n정렬 수행 시간 : %lf", (end - start));


	return 0;
}