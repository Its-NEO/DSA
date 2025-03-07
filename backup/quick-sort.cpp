#include <iostream>
#include <vector>

void swap(std::vector<int>& array, int posA, int posB)
{
	int temp = array[posA];
	array[posA] = array[posB];
	array[posB] = temp;
}

void quick_sort(std::vector<int>& array, int begin, int end)
{
	if (begin >= end) return;

	int pivot = array[end];
	int i = -1; int j = 0;

	while (j < end)
	{
		if (array[j] < pivot)
			swap(array, j, ++i);

		j++;
	}

	swap(array, ++i, end);
	quick_sort(array, 0, i - 1);
	quick_sort(array, i + 1, end);
}

int main()
{
	std::vector<int> test = {1, 6, 3, 7, 2, 9};
	quick_sort(test, 0, test.size() - 1);

	for (auto i : test)
	{
		std::cout << i << '\n';
	}

	return 0;
}
