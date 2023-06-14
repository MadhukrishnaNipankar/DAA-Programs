#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class MaxHeap
{
    int heap[MAX_SIZE];
    int size;

public:
    MaxHeap()
    {
        size = 0;
    }

    void insert(int value)
    {
        if (size == MAX_SIZE)
        {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        int i = size;
        heap[i] = value;
        ++size;

        while (i > 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }

        cout << "Element inserted successfully." << endl;
    }

    void remove()
    {
        if (size == 0)
        {
            cout << "Heap is empty. Cannot remove element." << endl;
            return;
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        --size;
        heapify(0);

        cout << "Element " << root << " removed successfully." << endl;
    }

    void heapify(int i)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return (2 * i) + 1;
    }

    int rightChild(int i)
    {
        return (2 * i) + 2;
    }

    void displayHeap()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << heap[i] << " ";
        }
    }
};

int main()
{
    MaxHeap maxHeap;
    maxHeap.insert(5);
    maxHeap.insert(10);
    maxHeap.insert(15);
    maxHeap.insert(3);
    maxHeap.insert(11);
    maxHeap.displayHeap();

    maxHeap.remove();
    maxHeap.displayHeap();
    maxHeap.remove();
    // maxHeap.remove();
    maxHeap.displayHeap();

    return 0;
}
