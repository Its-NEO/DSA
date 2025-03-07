#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
	int balance_f;

	Node(int value) : data {value}, left {nullptr}, right {nullptr}, balance_f{0} {}

	Node* insert(Node* node) {
		if (node->data < data)
		{
			if (left) left = left->insert(node);
			else left = node;
		}

		else if (node->data > data)
		{
			if (right) right = right->insert(node);
			else right = node;
		}

		balance_f = get_height(right) - get_height(left);

		if (balance_f < -1) {
			if (left->balance_f > 0) {
				left = rotate_left(left); 
			}
			return rotate_right(this); 
		}

		if (balance_f > 1) {
			if (right->balance_f < 0) {
				right = rotate_right(right); 
			}
			return rotate_left(this); 
		}

		return this;
	}

	Node* rotate_right(Node* node) {
		auto* left_right = node->left->right;
		auto* temp = node;

		node = node->left;
		node->right = temp;
		temp->left = left_right;

		return node;
	}

	Node* rotate_left(Node* node) {
		auto* right_left = node->right->left;
		auto* temp = node;

		node = node->right;
		node->left = temp;
		temp->right = right_left;

		return node;
	}

	int get_height(Node* node)
	{
		if (!node) return 0;
		return 1 + std::max(get_height(left), get_height(right));
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
		
		balance_f = get_height(left) - get_height(right);

		if (balance_f < -1) {
			if (left->balance_f > 0) {
				left = rotate_left(left); 
			}
			return rotate_right(this); 
		}

		if (balance_f > 1) {
			if (right->balance_f < 0) {
				right = rotate_right(right); 
			}
			return rotate_left(this); 
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
	
class AVLTree {
private:
    Node* root;

public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, new Node(value));
    }

    Node* insert(Node* node, Node* newNode) {
        if (!node) return newNode;
        node = node->insert(newNode);
        return node;
    }

    void display() {
        if (root) {
            root->depth_first_display("", "Root");
        } else {
            std::cout << "Tree is empty." << std::endl;
        }
    }

    Node* search(int value) {
        return root ? root->search(value) : nullptr;
    }
};

int main() 
{
}
