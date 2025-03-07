#include <iostream>
#include <queue>

struct Locator;

struct Node {
	int data;
	Node* left;
	Node* right;

	void depth_first_display(std::string prefix);
	void breadth_first_search(int data, std::vector<Locator>& locations);
};

struct Locator {
	Node* current;
	std::string location;
};

void Node::depth_first_display(std::string prefix) {
	std::cout << prefix << "--" << data << '\n';

	if (left) left->depth_first_display(prefix + "  |");
	if (right) right->depth_first_display(prefix + "  |");

	if (left || right) std::cout << prefix << '\n';

	return;
}

void Node::breadth_first_search(int data, std::vector<Locator>& locations) {
	std::queue<Locator> remaining;
	remaining.push({this, "H"});

	while (!remaining.empty())
	{
		Node* node = remaining.front().current;
		std::string current_location = remaining.front().location;
		remaining.pop();

		if (node->data == data)
			locations.push_back({node, current_location});

		if (node->left) remaining.push({node->left, current_location + "->L"});
		if (node->right) remaining.push({node->right, current_location + "->R"});
	}
}

class Tree {
	public:
	Node* head;

	Tree() : head {nullptr} {}

	void fill_tree() {
		head = new Node();
		bool filling = true;

		std::cout << "What is the value of the root node\n";
		int root;
		std::cin >> root;

		if (root == -1) return;

		if (!head) {
		    head = new Node();
		    head->data = root;
		}

		std::queue<Node*> to_be_filled;
		to_be_filled.push(head);
		while (!to_be_filled.empty())
		{
			Node* current = to_be_filled.front();
			to_be_filled.pop();

			std::cout << "What is the left child of " << current->data << ": ";
			int left;
			std::cin >> left;
			if (left != -1)
			{
				current->left = new Node();
				current->left->data = left;
				to_be_filled.push(current->left);
			}

			std::cout << "What is the right child of " << current->data << ": ";
			int right;
			std::cin >> right;
			if (right != -1)
			{
				current->right = new Node();
				current->right->data = right;
				to_be_filled.push(current->right);
			}
		}
	}

	void depth_first_display()
	{
		if (head == nullptr)
			std::cout << "Empty tree\n";
		else
			head->depth_first_display("|");
	}

	void breadth_first_search(int data, std::vector<Locator>& locations)
	{
		if (head == nullptr)
			std::cout << "Empty tree\n";
		else
			head->breadth_first_search(data, locations);
	}
};


int main()
{
	Tree tree;
	tree.fill_tree();
	int what;
	std::cout << "what to search? \n";
	std::cin >> what;
	tree.depth_first_display();
	std::vector<Locator> locations;
	tree.breadth_first_search(what, locations);
	for (auto i : locations) std::cout << i.location << '\n';
	return 0;
}
