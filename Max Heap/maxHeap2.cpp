#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class MaxHeap
{
    int heap[MAX_SIZE];
    int n;

public:
    MaxHeap()
    {
        n = 0;
    }

    void insertElement(int element)
    {
        n++;

        if (n == 1)
        {
            heap[n] = element;
            return;
        }

        heap[n] = element;

        int i = n;
        while (i > 1)
        {
            int parentIndex = getParentIndex(i);
            if (heap[parentIndex] < heap[i])
            {
                swap(heap[parentIndex], heap[i]);
            }
            else
            {
                return;
            }
        }
    }

    void removeElement()
    {
        if (n == 0)
        {
            std::cout << "Heap is already empty!!" << endl;
            return;
        }

        int temp = heap[1];
        heap[1] = heap[n];
        n--;
        heapify(1);

        std::cout << "Element " << temp << " removed successfully." << endl;
    }

    void heapify(int rootIndex)
    {
        int largest = rootIndex;
        int leftChildIndex = getLeftChildIndex(rootIndex);
        int rightChildIndex = getRightChildIndex(rootIndex);

        if (leftChildIndex < n && heap[rootIndex] < heap[leftChildIndex])
        {
            largest = leftChildIndex;
        }

        if (rightChildIndex < n && heap[largest] < heap[rightChildIndex])
        {
            largest = rightChildIndex;
        }

        if (largest != rootIndex)
        {
            swap(heap[largest], heap[rootIndex]);
            heapify(largest);
        }
    }

    int getParentIndex(int i)
    {
        return (int)i / 2;
    }

    int getLeftChildIndex(int parentIndex)
    {
        return (int)(parentIndex * 2);
    }

    int getRightChildIndex(int parentIndex)
    {
        return (int)((parentIndex * 2) + 1);
    }

    void print()
    {
        if (n == 0)
        {
        std:
            std::cout << "There is no element present inside the Heap" << endl;
        }

        for (int i = 1; i <= n; i++)
        {
            std::cout << heap[i] << " ";
        }
        std::cout << endl;
    }
};

int main()
{
    MaxHeap maxHeap;
    maxHeap.insertElement(5);
    maxHeap.insertElement(10);
    maxHeap.insertElement(15);
    maxHeap.insertElement(3);
    maxHeap.insertElement(11);
    maxHeap.print();

    maxHeap.removeElement();
    maxHeap.print();
    maxHeap.removeElement();
    // maxHeap.removeElement();
    maxHeap.print();
    return 0;
}