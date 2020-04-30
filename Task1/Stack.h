#pragma once
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Stack
{
private:
    T* array;
    int size;
    int head;
public:

    Stack(int count) {
        this->size = count;
        this->array = new T[size];
        this->head = 0;
    }

    Stack(const Stack<T>& stack) {
        this->head = stack.head;
        this->array = new T[stack.size];
        this->array = stack.array;
    }

    void push(T element)
    {
        if (this->head >= this->size) throw out_of_range("Stack is full!");
        array[this->head++] = element;
    }

    void pop()
    {
        if (this->head < 1) throw out_of_range("Stack is empty!");
        this->head--;
    }

    void print()
    {
        for (int i = 0; i < head; i++)
            cout << array[i] << " ";
        cout << endl;
    }

    ~Stack()
    {
        delete[] array;
    }

    void Merge(const Stack<T>& stack2);
};

template<typename T>
void Stack<T>::Merge(const Stack<T>& stack2)
{
    T* merge = new T[size + stack2.size];
    head = 0;
    while (head < size) {
        merge[head] = array[head];
        head++;
    }
    while (head < size + stack2.size) {
        merge[head] = stack2.array[head - size];
        head++;
    }
    array = merge;
}