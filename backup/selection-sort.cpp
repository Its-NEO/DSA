#include <iostream>

void swap(std::vector<int>& array, int posA, int posB)
{
	int temp = array[posA];
	array[posA] = array[posB];
	array[posB] = temp;
}

void selection_sort(std::vector<int>& array, int begin)
{
	if (begin >= array.size() - 1) return;

	int min = begin;
	for (int i = begin + 1; i < array.size(); i++)
	{
		if (array[i] < array[min]) min = i;
	}

	swap(array, min, begin);
	selection_sort(array, begin + 1);
}

int main()
{
	std::vector<int> test = {1, 6, 3, 7, 2, 9};
	selection_sort(test, 0);

	for (auto i : test)
	{
		std::cout << i << '\n';
	}

	return 0;
}
