#include <iostream>

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	int begin = 0;
	int end = 4;

	int element = 9;

	while (begin <= end)
	{
		int mid = begin + (end - begin) / 2;
		if (array[mid] == element)
		{
			std::cout << mid << '\n';
			std::cout << array[mid] << '\n';
			return 0;
		}

		if (element > array[mid])
			begin = mid + 1;
		else
			end = mid - 1;
	}

	std::cout << "Not found\n";
	return 0;
}
