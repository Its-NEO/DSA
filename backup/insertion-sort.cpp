#include <iostream>
#include <vector>

void swap(std::vector<int>& array, int posA, int posB)
{
	int temp = array[posA];
	array[posA] = array[posB];
	array[posB] = temp;
}

void insertion_sort(std::vector<int>& array, int begin)
{
	if (begin >= array.size()) return;

	int min_idx = begin;
	for (int i = begin + 1; i < array.size(); i++)
		if (array[i] < array[min_idx]) min_idx = i;

	for (int i = min_idx; i > begin; i--)
		swap(array, i, i - 1);

	insertion_sort(array, begin + 1);
}

int main()
{
	std::vector<int> test = {1, 6, 3, 7, 2, 9};
	insertion_sort(test, 0);

	for (auto i : test)
	{
		std::cout << i << '\n';
	}

	return 0;
}
