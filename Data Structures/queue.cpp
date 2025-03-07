#include <iostream>

class Queue {
	int* data;
	int begin;
	int end;

	int size = 1000;

public:
	Queue() : begin{-1}, end{0} {
		data = new int[size];
	}

	~Queue() {
		delete[] data;
	}

	void push(int value)
	{
		if (end == size) 
		{
			std::cout << "full queue\n";
			return;
		}

		if (begin == -1)
			begin = 0;

		data[end++] = value;
	}

	int pop()
	{
		if (begin == -1)
		{
			std::cout << "empty queue\n";
			return -999;
		}

		int value = data[begin++];

		if (begin == end)
		{
			begin = -1;
			end = 0;
		}

		return value;
	}
};

int main()
{
	Queue queue;
	queue.push(19);
	queue.push(9);
	queue.push(20);
	queue.push(9);
	queue.push(1);

	for (int i = 0; i < 5; i ++)
		std::cout << queue.pop()	<< std::endl;

	queue.pop();
}

