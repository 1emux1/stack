#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

// Initializing member variables
template <typename T>
Stack<T>::Stack() :
	currentSize(0),
	sData(nullptr)
{
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
	size_t _size = other.size();
	sData = new T[_size];

	// copying
	for (size_t ii = 0; ii < _size; ++ii) {
		sData[ii] = other.sData[ii];
	}
	currentSize = _size;
}

template <typename T>
Stack<T>::~Stack() {
	// Memory releasing in order to avoid unwanted leakage of memory
	currentSize = 0;
	delete[] sData;
	sData = nullptr;
}

template <typename T>
Stack<T>& Stack<T>::operator= (const Stack<T>& other) {
	// Self assignment
	if (this == &other)
		return *this;
	size_t _size = other.size();
	T *tmp = new T[_size]; // avoiding allocation fail, first allocate, after delete
	delete[] sData;
	sData = tmp;
	for (size_t jj = 0; jj < _size; ++jj) {
		sData[jj] = other.sData[jj];
	}
	currentSize = _size;

	return *this;
}

template <typename T>
inline size_t Stack<T>::size() const {
	return currentSize;
}

template <typename T>
inline bool Stack<T>::empty() {
	// if size is zero will return true, otherwise false
	return size() == 0;
}

template <typename T>
inline bool Stack<T>::full() {
	// if size of current stack is equal to capacity of stack, function will return true, otherwise false
	return size() == MAX_SIZE;
}

template <typename T>
 void Stack<T>::push(T value) {
	T* temp; // temporary pointer

	// check for stack overflow
	if (full()) {
		std::cerr << "Overflow happened, can not push element to the stack" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Allocating temporary memory
	temp = new T[currentSize + 1]; 

	// Copying original data to a newly allocated memory block
	for (size_t ii = 0; ii < currentSize; ++ii) {
		temp[ii] = sData[ii];
	}
	temp[currentSize] = value;

	// if not null, free
	if (sData != nullptr)
		delete[] sData;

	sData = temp;

	// after inserting current size should be incremented
	currentSize++;
}

template <typename T>
T Stack<T>::pop() {
	// temporary pointer and value to be returned
	T* temp;
	T poppedElement;

	// Check for stack undeflow
	if (empty()) {
		std::cerr << "Underflow happened, can not pop element from stack" << std::endl;
		exit(EXIT_FAILURE);
	}

	// store the last element in stack
	poppedElement = sData[currentSize - 1];
	// decreasing size of stack 
	currentSize--;

	// stack is not empty
	if (currentSize) {
		temp = new T[currentSize];

		// copy original data to temporart one
		for (size_t jj = 0; jj < currentSize; ++jj) {
			temp[jj] = sData[jj];
		}

		// Memory releasing
		if (sData != nullptr)
			delete[] sData;

		// temp -> sData
		sData = temp;
	}
	// When stack becomes empty
	else {
		if (sData != nullptr)
			delete[] sData;
		sData = nullptr;
	}
	return poppedElement;
}

template <typename T>
T Stack<T>::top() {
	if (!empty())
		return sData[currentSize - 1];
	else {
		std::cerr << "Stack is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
}

template <typename T>
inline void Stack<T>::print() const {
	// printing in reverse order
	for (size_t i = 0; i < currentSize; ++i)
		std::cout << sData[i] << " ";
	std::cout << '\n';
}

#endif // !STACK_CPP