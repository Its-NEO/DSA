#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> result;
	int lz = 0;
	int rz = 0;

	while (lz < left.size() && rz < right.size()) {
		result.push_back(std::min(left[lz], right[rz]));
		if (left[lz] < right[rz]) lz++; else rz++;
	}

	while (lz < left.size())
		result.push_back(left[lz++]);
	
	while (rz < right.size())
		result.push_back(right[rz++]);

	return result;
}

std::vector<int> merge_sort(std::vector<int> array) 
{
	if (array.size() == 1) return array;
	int mid = array.size() / 2;
	std::vector<int> left = merge_sort(std::vector<int> (array.begin(), array.begin() + mid));
	std::vector<int> right = merge_sort(std::vector<int> (array.begin() + mid, array.end()));

	return merge(left, right);
}

int main()
{
	std::vector<int> test = {9, 3, 1, 4};
	auto res = merge_sort(test);

	for (int i = 0; i < res.size(); i++)
		std::cout << res[i] << '\n';
	return 0;
}
