#pragma once
#include "party.h"
#include <fstream>
using namespace std;

class Stack {
	private:
		// array of party pointers
		Party ** data;
		int capacity;
		int numGuests;
		// expand capacity of data array (copy data into new array)
		void expand();
	public:
		int getCapacity();
		// constructors
		Stack();
		Stack(int startSize);
		Stack(const Stack & src);
		// destructor
		~Stack();
		// overloaded operators (assignment and output)
		Stack & operator = (const Stack & src);
		friend ostream & operator << (ostream & out, const Stack & src);
		// push a party onto the stack
		bool push(Party * p);
		// pop a party off the stack and add to contacts.txt
		bool pop();
		// peek at top of stack without editing it
		void peek() const;
		// display entire stack without editing it
		void display() const;
};
