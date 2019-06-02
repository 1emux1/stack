#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>

constexpr size_t MAX_SIZE = 200; // max capacity of stack

template <typename T>
class Stack {
private:
	T *sData; // pointer to data type
	size_t currentSize;  // currentSize

public:
	Stack(); // constructor
	Stack(const Stack<T>&); // copy constructor
	~Stack(); // destructor
	Stack<T>& operator=(const Stack<T>&); // assignment operator overloading
	size_t size() const; // returns current size of stack
	void push(T); // inserting elementing at the end of stack
	T pop(); // popping element which is on the top of the element of stack and decreases size of stack by one for each pop
	T top(); // returning peek element in stack without modifying
	bool empty(); // check for empty stack
	bool full(); // check for full stack
	void print() const;
};

#include "Stack.cpp"
#endif // !STACK_H
