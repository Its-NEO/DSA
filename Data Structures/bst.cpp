#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value) : data {value}, left {nullptr}, right {nullptr} {}

	void insert(Node* node) {
		if (node->data < data)
		{
			if (left) left->insert(node);
			else left = node;
		}

		else if (node->data > data)
		{
			if (right) right->insert(node);
			else right = node;
		}
	}

	Node* find_parent(int value) {
		if (left && left->data == value)
			return this;

		if (right && right->data == value)
			return this;

		if (value > data && right)
			return right->find_parent(value);
		else if (value < data && left)
			return left->find_parent(value);

		return nullptr;
	}

	int find_min_value()
	{
		if (left) return left->find_min_value();
		else return data;
	}

	Node* remove(int value) {
		Node* parent = find_parent(value);
		if (!parent) return this;  

		bool is_left = (parent->left && parent->left->data == value);
		Node* child = is_left ? parent->left : parent->right;

		if (child->left && child->right)
		{
			int min_value = child->right->find_min_value();
			child->data = min_value;
			child->right = child->right->remove(min_value);  
		}
		else if (child->left || child->right)
		{
			Node* replacement = (child->left) ? child->left : child->right;
			if (is_left) 
				parent->left = replacement;
			else 
				parent->right = replacement;
			delete child;
		}
		else
		{
			if (is_left) parent->left = nullptr;
			else parent->right = nullptr;
			delete child;
		}

		return this;  
	}

	Node* search(int value) {
		if (data == value) 
			return this;

		if (data < value)
			return (right) ? right->search(value) : right; 

		return (left) ? left->search(value) : left;
	}

	void depth_first_display(std::string prefix, std::string location) {
		std::cout << prefix << "--" << data << "  [" << location << ']' << '\n';

		if (left) left->depth_first_display(prefix + "  |", "L");
		if (right) right->depth_first_display(prefix + "  |", "R");

		if (left || right) std::cout << prefix << '\n';

		return;
	}
};

class Tree {
	public:
		Node* head;

		Tree() : head {nullptr} {}
		void insert(int data)
		{
			if (!head)
				head = new Node {data};
			else
				head->insert(new Node {data});
		}

		Node* search(int data)
		{
			if (!head)
				return nullptr;

			return head->search(data);
		}

		void remove(int data)
		{
			if (head && head->data == data) 
			{
				delete head;
				head = nullptr;
				return;
			}

			head->remove(data);
		}

		void display() 
		{
			if (head) head->depth_first_display("|", "H");
		}
};

int main()
{
	Tree tree;
	int input;
	while (true)
	{
		std::cin >> input;
		if (input == -1) break;

		tree.insert(input);
	}

	std::cout << "Initial Tree:" << std::endl;;
	tree.display();

	while (true)
	{
		std::cin >> input;
		tree.remove(input);
		std::cout << "Removed " << input << '\n';
		tree.display();
	}
	
	std::cout << "Final	Tree:" << std::endl;
	tree.display();

	return 0;
}
