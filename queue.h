#pragma once
#include "stack.h"
#include "party.h"
using namespace std;

class Queue {
	private:
		struct Node {
			Party * data;
			Node * next;
			// used only when copying queues
			Node(const Node & src) {
				data = new Party(*(src.data));
				next = nullptr;
			}
			// only to be used for new parties
			Node(Party * myParty) {
				data = myParty;
				next = nullptr;
			}
			~Node() {
				if (this->data) {
					delete data;
				}
			}
		};
		Node * front;
		Node * rear;
		int size;
	public:
		// constructors
		Queue();
		Queue(const Queue & src);
		// destructor
		~Queue();
		// overloaded operators (assignment and output)
		Queue & operator = (const Queue & src);
		friend ostream & operator << (ostream & out, const Queue & src);
		// add party to queue
		bool enqueue(Party * p);
		// copy onto destination stack, then delete from queue
		bool dequeue(Stack * dest);
		// display front of queue without altering list
		void peek() const;
		// display entire list without altering it
		void display() const;
};
