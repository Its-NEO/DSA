![[img_mergesort_long.png]]

# Intuition

This algorithm is quite simple yet quite confusing. These are the steps to this algorithm:

- **Step 1** : Divide the given array into halves of two until it cannot be subdivided.
- **Step 2** : Now merge the subarrays, in such a way that the elements are placed at its correct position. To do that, we iterate through the left half and the right half and keep placing the elements that are smaller than the other. 
  `if left[top] < right[top] then result.append(left[top]) else result.append(right[top])`

# Building the code

We need to divide the array into halves of two until it cannot be subdivided. 

```c++
--- merge_sort(std::vector<int> array)
{
	// base case
	if (array.size() == 1) return array;
	
	// further subdivide the left part
	merge_sort(std::vector<int>(array.begin(), array.begin() + array.size() / 2));
	
	// and the right part
	merge_sort(std::vector<int>(array.begin() + array.size() / 2, array.end()));
}
```

Remember, merge sort is not a **in place** sorting algorithm. It doesn't sort the array by rearranging the elements in its own self. It returns a sorted array. So, let's add that.

```c++
std::vector<int> merge_sort(std::vector<int> array)
{
	...
}
```

After we are done subdividing the main array, the next step is to merge them. Now we will use a function called `merge_them` for merging them.

```c++
std::vector<int> merge_sort(std::vector<int> array)
{
	if (array.size() == 1) return array;
	
	// take the left half
	auto left = merge_sort(std::vector<int>(array.begin(), array.begin() + array.size() / 2));
	
	// and the right half
	auto right = merge_sort(std::vector<int>(array.begin() + array.size() / 2, array.end()));
	
	// and merge them	
	return merge_them(left, right);
}
```

This ensures that when we move from the deepest pits of the recursion up to the first call to that function, we keep merging and returning. This means, when we call `merge_sort` on this line, `auto left = mer...` we are subdividing and diving deep into the pits of recursion until we hit the rock bottom, from which we are climbing up and as we go... we keep merging them. 

Now we show how we merge them.

```c++
std::vector<int> merge_them(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> temp;
	auto lit = left.begin();
	auto rit = right.begin();
	
	// check which is lower, the left or the right, and keep that one
	while(lit != left.end() && rit != right.end())
		temp.push_back((*lit < *rit) ? *lit++ : *rit++);
	
	// do not forget to add back the remaining elements
	while (lit != left.end())
		temp.push_back(*lit++);
	
	while (rit != right.end())
		temp.push_back(*rit++);
	
	return temp;
}
```

# Code

```c++
#include <iostream>
#include <vector>

std::vector<int> merge_them(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> temp;
	auto lit = left.begin();
	auto rit = right.begin();
	
	while(lit != left.end() && rit != right.end())
		temp.push_back((*lit < *rit) ? *lit++ : *rit++);
	
	while (lit != left.end())
		temp.push_back(*lit++);
	
	while (rit != right.end())
		temp.push_back(*rit++);
	
	return temp;
}

std::vector<int> merge_sort(std::vector<int> array)
{
	if (array.size() == 1)
		return array;
	
	auto left = merge_sort(std::vector<int>(array.begin(), array.begin() + array.size() / 2));
	auto right = merge_sort(std::vector<int>(array.begin() + array.size() / 2, array.end()));

	return merge_it(left, right);
}


int main() {
	std::vector<int> array {1, 5, 2, 4, 3};
	std::vector<int> answer = merge_sort(array);
	
	for (auto i : answer)
		std::cout << i << std::endl;
	
	return 0;
}
```

# Algorithm

```
Algorithm MergeSort(ARRAY, size)
{
    if (size == 1)
        return ARRAY;
    
    mid = size / 2;
    
    LEFT = MergeSort(ARRAY[0 : mid], mid);
    RIGHT = MergeSort(ARRAY[mid : size], size - mid);
    
    return Merge(LEFT, mid, RIGHT, size - mid);
}

Algorithm Merge(LEFT, leftSize, RIGHT, rightSize)
{
    TEMP[leftSize + rightSize];
    
    pos = 0;
    leftIdx = 0;
    rightIdx = 0;
    
    while (leftIdx < leftSize && rightIdx < rightSize)
    {
        if (LEFT[leftIdx] < RIGHT[rightIdx])
            TEMP[pos++] = LEFT[leftIdx++];
        else
            TEMP[pos++] = RIGHT[rightIdx++];
    }
    
    while (leftIdx < leftSize)
        TEMP[pos++] = LEFT[leftIdx++];
    
    while (rightIdx < rightSize)
        TEMP[pos++] = RIGHT[rightIdx++];
    
    return TEMP;
```
