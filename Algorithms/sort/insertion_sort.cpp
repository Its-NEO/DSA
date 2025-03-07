#include <iostream>

void sort(int* array, int begin, int end)
{
	if (begin > end) return;

	if (array[begin] < array[begin - 1])
	{
		int pos = begin - 1;
		while (pos >= 0 && array[begin] < array[pos])
				pos--;

		pos++;  

		int copy = array[begin];

		for (int i = begin; i > pos; i--)
			array[i] = array[i - 1];

		array[pos] = copy;  
	}

	sort(array, begin + 1, end);
}

int main()
{
	int array[] = {6, 2, 3, 7, 1};
	sort(array, 1, 4);

	for (int i = 0; i < 5; i++)
		std::cout << array[i] << '\n';

	return 0;
}
