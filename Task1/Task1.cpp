#include "Stack.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    Stack<int> stack1(4);
    Stack<int> stack2(5);
    stack1.push(1);
    stack1.push(3);
    stack1.pop();
    stack1.push(5);
    stack1.push(7);
    stack1.push(9);
    cout << "Стек 1: "; stack1.print();
    stack2.push(2);
    stack2.push(4);
    stack2.push(6);
    stack2.push(8);
    stack2.push(10);
    cout << endl <<"Стек 2: "; stack2.print();
    stack1.Merge(stack2);
    cout << endl <<"Стек 1 + 2: "; stack1.print();
}