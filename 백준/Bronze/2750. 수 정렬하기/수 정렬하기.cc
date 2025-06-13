#include <iostream>

void Swap(int* a, int* b)
{
	
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Median(int a, int b, int c)
{
	if(a > b)
		Swap(&a, &b);
	if(b > c)
		Swap(&b, &c);
	if(a > b)
		Swap(&a, &b);
	return b;

}

void Quicksort(int * arr, int start, int end)
{
	if(start >= end)
		return;
	int mid = (start + end) / 2;
	int pivot = Median(start, mid, end);
	Swap(&arr[start], &arr[pivot]);
	pivot = start;
	
	int left = start + 1;
	int right = end;

	while(left <= right)
	{
		while(arr[left] <= arr[pivot] && left <= end) 
			left++;
		while(arr[right] >= arr[pivot] && right > start)
			right--;
		if(left <= right)
			Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[pivot], &arr[right]);
	mid = right;

	Quicksort(arr, start, mid - 1);
	Quicksort(arr, mid + 1, end);
	
}

int main(void)
{
	int N;
	std::cin >> N;
	int *arr = new int[N];
	for(int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	Quicksort(arr, 0, N-1);

	for(int i = 0; i < N; i++)
	{
		std::cout << arr[i] << '\n';
	}
	delete[] arr;
	return 0;
}