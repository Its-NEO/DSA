#include <iostream>

struct Node {
	int key {};
	double value {};
};

class HashMap 
{
	int SIZE;
	Node* array;
	public:
	HashMap(int SIZE) : SIZE {SIZE}, array {new Node {SIZE}}  {}
	HashMap() : HashMap {10000} {}

	void insert(Node node) {
	}

	void remove(Node node) {
	}

	void display() {
	}

	private:
	int lprob(int key) {
		for (int i = 0; i < SIZE; i++) {
			int hash = (key + i) % SIZE;
			if (array[hash]) return hash;
		}

		return -1;
	}

	int qprob(int key) {
		for (int i = 0; i < SIZE; i++) {
			int hash = (key + i * i) % SIZE;
			if (array[hash]) return hash;
		}

		return -1;
	}

	bool is_prime(int num) {
		int factors = 0;
		for (int i = 2; i <= num / 2; i++)
		{
			if (num % i == 0) factors++;
		}

		return factors == 0;
	}

	int dhash_h2(int key) {
		int prime;
		for (int i = SIZE; i > 0; i--)
		{
			if (is_prime(i)) 
			{
				prime = i;
				break;
			}
		}

		return key % prime;
	}

	int dhash(int key) {
		for (int i = 0; i < SIZE; i++) {
			int hash = (key + i * dhash_h2(key)) % SIZE;
			if (array[hash]) return hash;
		}

		return -1;
	}
};

int main()
{
}
