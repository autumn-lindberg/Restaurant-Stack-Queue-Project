#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Party {
	private:
		char * name;
		int numPeople;
		char accomodation;
		bool promos;
	public:
		// constructors
		Party();
		Party(const Party & src);
		Party(char * name, int people, char accomodation, bool promos);
		// destructor
		~Party();
		// overloaded operators (assignment and output)
		Party & operator = (const Party & src);
		friend ostream & operator << (ostream & out, const Party & src);
		// getters
		char * getName() const;
		int getNumPeople() const;
		char getAccomodation() const;
		bool getPromos() const;
		// setters
		void setName(char * name);
		void setNumPeople(int people);
		void setAccomodation(char accomodation);
		void setPromos(bool promo);
		// display a single party
		void display() const;
};
