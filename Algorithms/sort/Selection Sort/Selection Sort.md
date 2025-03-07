![[selection-short.png]]

# Intuition

 Well, this is the most obvious form of sorting. We start from the left, and 
 
 - **Step 1** : Search for the smallest element in the unsorted subarray.
 - **Step 2** : Put the element in the sorted part of the array and repeat.

Its how we humans would sort if we were given cards labelled with some numbers. Easy peasy.

# Building the code

Selection sort is in-place as well.

```c++
void selection_sort(int array[], int begin, int end)
{
	// base case
	if (begin >= end) return;
}
```

Now we find the minimum element. Keep in mind that the sorted part lies before `begin`.

```c++
int min = begin;
for (int i = begin + 1; i <= end; i++)
{
	if (array[i] < array[min])
		min = i;
}
```

Now just swap it with the first unsorted part of the array.

```c++
int temp = array[begin];
array[begin] = array[min];
array[min] = temp;
```

rinse and repeat...

```c++
selection_sort(array, begin + 1, end);
```

# Code

```c++
#include <iostream>

void selection_sort(int array[], int begin, int end)
{
	if (begin >= end) return;
	
	int min = begin;
	for (int i = begin + 1; i <= end; i++)
	{
		if (array[i] < array[min])
			min = i;
	}
	
	int temp = array[begin];
	array[begin] = array[min];
	array[min] = temp;
	
	selection_sort(array, begin + 1, end);
}

int main()
{
	int array[] = {5, 3, 1, 2, 6, 5};
	selection_sort(array, 0, 5);
	
	for (auto i : array)
	{
		std::cout << i << '\n';
	}
	return 0;
}
```

# Algorithm

```
Algorithm SelectionSort(ARRAY, begin, end)
{
	if (begin >= end) return;
	
	min = begin;
	for (i = begin + 1 to end)
	{
		if (ARRAY[i] < ARRAY[min])
			min = i;
	}
	
	temp = ARRAY[begin];
	ARRAY[begin] = ARRAY[min];
	ARRAY[min] = temp;
	
	SelectionSort(ARRAY, begin + 1, end);
}
```