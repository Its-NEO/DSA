![[0*3GYw87Ix_9BOQXn6.png]]

# Intuition

Bubble sort is an in-place sorting algorithm which works on the principle of pushing elements on the right-hand side as we pass through an array like waves passing on a river. The heavier elements gets pushed towards the direction of the wave and the heaviest end up at the end. Well this is the intuition of bubble sort.

- **Step 1** : Iterate through the array and compare the elements with the one in-front of them. 
- **Step 2** : If the element is larger than the one after it, swap them.
- **Step 3** : Rinse and repeat until the array is sorted.

# Code 

```c++
void bubble_sort(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		// when this runs once, the largest element will be
		// at the end. we need to run it once for every element
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
```

# Algorithm

```
Algorithm BubbleSort(ARRAY, size)
{
	for (i = 0 to size - 1)
	{
		for (j = 0 to size - i - 2)
		{
			if (ARRAY[j] > ARRAY[j + 1])
			{
				temp = ARRAY[j];
				ARRAY[j] = ARRAY[j + 1];
				ARRAY[j + 1] = temp;
			}
		}
	}
}
```