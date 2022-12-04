#include "queue.h"
using namespace std;

// constructors
Queue::Queue() {
	this->size = 0;
	this->front = nullptr;
	this->rear = nullptr;
}
Queue::Queue(const Queue & src) {
	// make new node for front
	this->front = new Node(*(src.front));
	this->rear = this->front;
	this->size = 1;
	// create parallel currents
	Node * current = src.front;
	Node * thisCurrent = this->front;
	// cycle thru list (stop one before end)
	int index = 1;
	while ((index % src.size) != 0) {
		// look ahead and copy data
		thisCurrent->next = new Node(*(current->next));
		this->rear = thisCurrent->next;
		// advance currents
		current = current->next;
		thisCurrent = thisCurrent->next;
		index++;
		this->size++;
	}
	this->rear->next = this->front;
}
// destructor
Queue::~Queue() {
	Node * current = this->front;
	Node * dummy = nullptr;
	int index = 0;
	while (index != size) {
		dummy = current;
		current = current->next;
		delete dummy;
		index++;
	}
}
// overloaded operators (assignment and output)
Queue & Queue::operator = (const Queue & src) {
	if (this != &src) {
		Node * current = this->front;
		Node * dummy = nullptr;
		int index = 0;
		while (index != size) {
			dummy = current;
			current = current->next;
			delete dummy;
			index++;
		}
		current = this->front;
		index = 0;
		while (index != size) {
			Party * p = new Party(*(current->data));
			enqueue(p);
			index++;
		}
	}
	return *this;
}
ostream & operator << (ostream & out, const Queue & src) {
	src.display();
	return out;
}
// add party to queue
bool Queue::enqueue(Party * p) {
	Node * n = new Node(p);
	// if list is empty
	if (!this->front) {
		this->front = n;
		this->rear = n;
		n->next = n;
	}
	else {
		// add to rear of queue 
		this->rear->next = n;
		this->rear = n;
		n->next = this->front;
	}
	this->size += 1;
	return true;
}
// add a copy to stack, then delete from queue
bool Queue::dequeue(Stack * dest) {
	// if empty
	if (!this->front) {
		return false;
	}
	else {
		if (this->front->data->getPromos() == 1) {
			Party * dummy = new Party(*(this->front->data));
			dest->push(dummy);
		}
		// do removal
		Node * head = this->front;
		this->rear->next = this->front->next;
		this->front = this->front->next;
		delete head;
		this->size--;
	}
	return true;
}
// display front of queue without altering list
void Queue::peek() const {
	cout << endl;
	cout << *(this->front->data);
	cout << endl;
}
// display entire list without altering it
void Queue::display() const {
	Node * current = this->front;
	int index = 0;
	cout << left << endl;
	cout << setw(20) << "PLACE IN QUEUE";
	cout << setw(25) << "PARTY NAME";
	cout << setw(10) << "SIZE";
	cout << setw(20) << "ACCOMODATIONS";
	cout << setw(15) << "GET PROMOS?";
	cout << endl << endl;
	while (index != size) {
		cout << setw(20) << index + 1;
		cout << *(current->data);
		current = current->next;
		index++;
	}
	cout << endl;
}
