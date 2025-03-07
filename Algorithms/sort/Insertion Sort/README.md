![Insertion Sort Image](../../../Images/insertion-sort.png)

# Intuition

Insertion sort is just like selection sort with the difference being the mode of its operation. While selection sort swaps the elements from the unsorted area to the sorted area, this inserts the first element to it's correct position in the sorted array. So, a linked list would be better in this case instead of an array.

# Code \[Array\]

```c++
#include <iostream>

void insertionSort(int* array, int begin, int end)
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
	insertionSort(array, 1, 4);
	
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << '\n';
		
	return 0;
}
```

# Algorithm

```
Algorithm insertionSort(ARRAY, begin, end)
{
	if (begin > end) return;
	
	if (array[begin] < array[begin - 1])
	{
		pos = begin - 1;
		
		while (pos >= 0 and ARRAY[begin] < ARRAY[pos])
			pos--;
		
		pos++;
		
		copy = ARRAY[begin];
		
		for (i = begin to pos - 1)
			ARRAY[i] = ARRAY[i - 1];
			
		ARRAY[pos] = copy;
	}
	
	insertionSort(ARRAY, begin + 1, end);
}
```
