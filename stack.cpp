#include "stack.h"
using namespace std;

// helper function to test program
int Stack::getCapacity() {
	return this->capacity;
}
// expand if not enough space
void Stack::expand() {
	Party ** dummy = new Party * [(this->numGuests * 2)];
	// copy into bigger array
	for (int i = 0; i < numGuests; i++) {
		dummy[i] = this->data[i];
	}
	// delete old array
	delete [] this->data;
	this->data = new Party * [(this->numGuests * 2)];
	// copy back into this data
	for (int i = 0; i < numGuests; i++) {
		this->data[i] = dummy[i];
	}
	delete [] dummy;
	this->capacity = this->numGuests * 2;
}
// constructors
Stack::Stack() {
	this->capacity = 1;
	this->numGuests = 0;
	this->data = nullptr;
}
Stack::Stack(int startSize) {
	this->data = new Party * [startSize];
	this->capacity = startSize;
	this->numGuests = 0;
}
Stack::Stack(const Stack & src) {
	this->data = new Party * [src.capacity];
	this->capacity = src.capacity;
	this->numGuests = src.numGuests;
	for (int i = 0; i < this->capacity; i++) {
		// only copy if cell is not nullptr
		if (src.data[i]) {
			this->data[i] = new Party(*(src.data[i]));
		}
	}
}
// destructor
Stack::~Stack() {
	for (int i = 0; i < numGuests; i++) {
		delete this->data[i];
	}
	delete [] this->data;
	this->capacity = 1;
	this->numGuests = 0;
	this->data = nullptr;
}
// overloaded operators (assignment and output)
Stack & Stack::operator = (const Stack & src) {
	if (this != &src) {
		for (int i = 0; i < numGuests; i++) {
			delete this->data[i];
		}
		delete [] this->data;
		this->data = new Party * [src.capacity];
		this->capacity = src.capacity;
		this->numGuests = src.numGuests;
		for (int i = 0; i < capacity; i++) {
			// only copy if cell is not nullptr
			if (src.data[i]) {
				*(this->data[i]) = *(src.data[i]);
			}
		}
	}
	return *this;
}
ostream & operator << (ostream & out, const Stack & src) {
	src.display();
	return out;
}
// push a party onto the stack
bool Stack::push(Party * p) {
	if (this->numGuests == this->capacity) {
		this->expand();
	}
	// numGuests index is first empty slot
	data[this->numGuests] = p;
	this->numGuests++;
	return true;
}
// pop a party off the stack and add to contacts.txt
bool Stack::pop() {
	char * name = nullptr;
	ofstream outFile;
	outFile.open("contacts.txt");
	if (!outFile) {
		cout << "Error opening file!" << endl;
		return false;
	}
	name = this->data[this->numGuests - 1]->getName();
	outFile << name;
	outFile << ',';
	outFile << this->data[this->numGuests - 1]->getNumPeople();
	outFile << ',';
	outFile << this->data[this->numGuests - 1]->getAccomodation();
	outFile << ',';
	outFile << this->data[this->numGuests - 1]->getPromos();
	outFile << '\n';
	delete this->data[this->numGuests - 1];
	this->data[this->numGuests - 1] = nullptr;
	this->numGuests--;
	delete [] name;
	return true;
}
// peek at top of stack without editing it
void Stack::peek() const {
	cout << endl;
	cout << setw(25) << "PARTY NAME";
	cout << setw(10) << "SIZE";
	cout << setw(20) << "ACCOMODATIONS";
	cout << setw(15) << "GET PROMOS?";
	cout << endl << endl;
	cout << *(this->data[this->numGuests - 1]);
	cout << endl;
}
// display entire stack without editing it
void Stack::display() const {
	cout << endl;
	cout << setw(25) << "PARTY NAME";
	cout << setw(10) << "SIZE";
	cout << setw(20) << "ACCOMODATIONS";
	cout << setw(15) << "GET PROMOS?";
	cout << endl << endl;
	// print backwards so it looks like a stack
	for (int i = this->numGuests - 1; i >= 0; i--) {
		cout << *(this->data[i]);
	}
	cout << endl;
}
