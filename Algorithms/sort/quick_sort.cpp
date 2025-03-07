#include <iostream>

void quick_sort(int* array, int begin, int end)
{
	if (begin >= end) return;

	int i = begin - 1;
	int j = begin;
	while (j < end)
	{
		if (array[j] < array[end])
		{
			i++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}

		j++;
	}

	i++;
	int temp = array[i];
	array[i] = array[end];
	array[end] = temp;

	quick_sort(array, begin, i - 1);
	quick_sort(array, i + 1, end);
}	

int main()
{
	int array[] = {8, 2, 4, 7, 1, 3, 9, 6, 5};
	quick_sort(array, 0, 8);

	for (auto i : array)
		std::cout << i << '\n';
}
