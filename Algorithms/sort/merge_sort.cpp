#include <iostream>
#include <vector>

std::vector<int> merge_it(std::vector<int> left, std::vector<int> right)
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


