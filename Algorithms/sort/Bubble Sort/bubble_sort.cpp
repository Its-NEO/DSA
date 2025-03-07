#include <iostream>

void bubble_sort(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int array[] = {1, 2, 3, 2, 4, 5};
	bubble_sort(array, 6);
	for (int i = 0; i < 6; i++)
		std::cout << array[i] << '\n';

	return 0;
}
