#include <iostream>

void selection_sort(int array[], int begin, int end)
{
	if (begin >= end) return;

	int min = begin;
	for (int i = begin + 1; i <= end; i++)
	{
		if (array[i] < array[min])
			min = i;
	}

	int temp = array[begin];
	array[begin] = array[min];
	array[min] = temp;

	selection_sort(array, begin + 1, end);
}

int main()
{
	int array[] = {5, 3, 1, 2, 6, 5};
	selection_sort(array, 0, 5);

	for (auto i : array)
	{
		std::cout << i << '\n';
	}
	return 0;
}
