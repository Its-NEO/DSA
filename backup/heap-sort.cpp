#include <iostream>
#include <vector>

void swap(std::vector<int>& array, int posA, int posB)
{
	int temp = array[posA];
	array[posA] = array[posB];
	array[posB] = temp;
}

void heapify(std::vector<int>& array, int size, int root)
{
	int left = root * 2 + 1;
	int right = root * 2 + 2;

	int highest = root;

	if (left < size && array[left] > array[highest]) highest = left;
	if (right < size && array[right] > array[highest]) highest = right;
	if (highest != root) 
	{
		swap(array, highest, root);
		heapify(array, size, highest);
	}
}

void heap_sort(std::vector<int>& array)
{
	for (int i = array.size() / 2 - 1; i >= 0; i --) {
		heapify(array, array.size(), i);
	}

	for (int i = array.size() - 1; i > 0; i--) {
		swap(array, 0, i);
		heapify(array, i, 0);
	}
}

int main()
{
	std::vector<int> test = {1, 6, 3, 7, 2, 9};
	heap_sort(test);

	for (auto i : test)
	{
		std::cout << i << '\n';
	}

	return 0;
}

