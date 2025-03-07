#include <iostream>

class MinHeap {
    int* array;
    int pointer;
    const int MAX_SIZE;
    
    void bubble_up() {
        int copy_ptr = pointer - 1;
        int parent_idx = (copy_ptr - 1) / 2;

        while (parent_idx >= 0 && array[copy_ptr] < array[parent_idx])
        {
            int value = array[copy_ptr];
            array[copy_ptr] = array[parent_idx];
            array[parent_idx] = value;

            copy_ptr = parent_idx;
            parent_idx = (copy_ptr - 1) / 2;
        }
    }

    void bubble_down() {
        int copy_ptr = 0;
        int left_child = (copy_ptr * 2) + 1;
        int right_child = (copy_ptr * 2) + 2;

        while (left_child < pointer)  
        {
            int swap_pos = (right_child < pointer && array[right_child] < array[left_child]) ? right_child : left_child;
            if (array[copy_ptr] <= array[swap_pos]) break;

            int value = array[copy_ptr];
            array[copy_ptr] = array[swap_pos];
            array[swap_pos] = value;

            copy_ptr = swap_pos;
            left_child = (copy_ptr * 2) + 1;
            right_child = (copy_ptr * 2) + 2;
        }
    }

public:
    MinHeap(int size) : array { new int[size]{} }, pointer{} , MAX_SIZE {size} {}
    MinHeap() : MinHeap{100} {}

    void insert(int data)
    {
        if (pointer >= MAX_SIZE) {
            std::cout << "Heap overflow\n";
            return;
        }
        array[pointer++] = data;
        bubble_up();
    }

    void remove() {
        array[0] = array[--pointer];
        bubble_down();
    }

    void display()
    {
        for (int i = 0; i < pointer; i++)
            std::cout << array[i] << "  ";
        std::cout << '\n';
    }

    bool empty()
    {
        return pointer == 0;
    }
};

int main() {
    MinHeap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(25);

    heap.display();

    while (!heap.empty())
    {
        heap.remove();
        heap.display();
    }

    return 0;
}

