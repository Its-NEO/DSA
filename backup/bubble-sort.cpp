#include <iostream>
#include <vector>

void swap(std::vector<int>& array, int posA, int posB)
{
	int temp = array[posA];
	array[posA] = array[posB];
	array[posB] = temp;
}

void bubble_sort(std::vector<int>& array)
{
	for (int i = 0; i < array.size() - 2; i++)
	{
		for (int j = 0; j < array.size() - 1 - i; j ++)
		{
			if (array[j] > array[j+1])
				swap(array, j, j + 1);
		}
	}
}

int main()
{
	std::vector<int> test = {1, 6, 3, 7, 2, 9};
	bubble_sort(test);

	for (auto i : test)
	{
		std::cout << i << '\n';
	}

	return 0;
}
