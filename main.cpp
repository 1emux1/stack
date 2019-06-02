#include "Stack.h"
#include <string>

/* Testing of Queue class */

int main() {
	std::cout << "\t\t\t\t\t ***  Testing Stack implementation  ***";
	std::cout << std::string(3, '\n');

	/* Test for char data type */
	std::cout << "Testing for char data type" << "\n\n";

	// char data type, initialization, constructor is called
	Stack<char> S;

	// testing push function
	char ch;
	for (ch = 'A'; ch <= 'F'; ++ch) {
		std::cout << "Pushing: " << ch << '\n';
		S.push(ch);
	}
	std::cout << '\n';

	// testing size function
	std::cout << "Size of stack is: " << S.size() << '\n';

	// testing copy constructor
	Stack<char> S1(S);
	S1.print();

	//testing top function
	std::cout << "Peek element in stack S: " << S.top() << '\n';

	// testing assignment operator
	std::cout << "Assignment operator: ";
	Stack<char> S2;
	std::cout << "Assigning happening and printing elements of newly created stack: ";
	S2 = S;
	S2.print();
	std::cout << '\n';

	// testing pop function
	while (!S.empty()) {
		std::cout << "Popping: " << S.top() << '\n';
		S.pop();
	}
	std::cout << '\n';

	// check for full
	S.full() ? std::cout << "Stack is full" : std::cout << "Stack is not full";
	std::cout << '\n';

	// check for empty
	S.empty() ? std::cout << "Stack is empty" : std::cout << "Stack is not empty";
	std::cout << std::string(3, '\n');

	/*********************************************************************** END FOR CHAR*/
	
	/* Test for int data type */
	std::cout << "Testing for int data type" << "\n\n";

	// int data type, initialization, constructor is called
	Stack<int> s;

	// testing push
	for (int i = 14; i <= 20; ++i) {
		std::cout << "Pushing: " << i << '\n';
		s.push(i);
	}
	std::cout << '\n';

	// testing size function
	std::cout << "Size of stack is: " << s.size() << '\n';

	// testing copy constructor
	Stack<int> s1(s);
	s1.print();

	//testing front and back functions
	std::cout << "Peek element in stack s: " << s.top() << '\n';

	// testing assignment operator
	std::cout << "Assignment operator: ";
	Stack<int> s2;
	std::cout << "Assigning happening and printing elements of newly created stack: ";
	s2 = s;
	s2.print();
	std::cout << '\n';

	// testing pop function
	while (!s.empty()) {
		std::cout << "Popping: " << s.top() << '\n';
		s.pop();
	}
	std::cout << '\n';

	// check for full
	s.full() ? std::cout << "Stack is full" : std::cout << "Stack is not full";
	std::cout << '\n';

	// check for empty
	s.empty() ? std::cout << "Stack is empty" : std::cout << "Stack is not empty";

	/************************************************************************* END FOR INT*/
	
	std::cin.get(); // in order to prevent console closing when running program
	return 0;
}