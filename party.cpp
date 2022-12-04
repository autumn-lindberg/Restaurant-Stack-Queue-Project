#include "party.h"
using namespace std;

// constructors
Party::Party() {
	this->name = new char[2];
	strcpy(this->name, " ");
	this->numPeople = 0;
	this->accomodation = 'n';
	this->promos = false;
}
Party::Party(const Party & src) {
	this->name = new char[strlen(src.name) + 1];
	strcpy(this->name, src.name);
	this->numPeople = src.numPeople;
	this->accomodation = src.accomodation;
	this->promos = src.promos;
}
Party::Party(char * name, int people, char accomodation, bool promos) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->numPeople = people;
	this->accomodation = accomodation;
	this->promos = promos;
}
// destructor
Party::~Party() {
	if (this->name) {
		delete [] this->name;
		this->name = nullptr;
	}
	this->numPeople = 0;
	this->accomodation = 'n';
	this->promos = false;
}
// overloaded operators (assignment and output)
Party & Party::operator = (const Party & src) {
	// don't self-copy
	if (this != &src) {
		if (this->name) {
			delete [] this->name;
			this->name = nullptr;
		}
		this->name = new char[strlen(src.name) + 1];
		strcpy(this->name, src.name);
		cout << "name after copy: " << this->name << endl;
		this->numPeople = src.numPeople;
		this->accomodation = src.accomodation;
		this->promos = src.promos;
	}
	return *this;
}
ostream & operator << (ostream & out, const Party & src) {
	src.display();
	return out;
}
// getters
char * Party::getName() const {
	if (!(this->name)) {
		return nullptr;
	}
	else {
		char * nameCopy = new char[strlen(this->name) + 1];
		strcpy(nameCopy, this->name);
		return nameCopy;
	}
}
int Party::getNumPeople() const {
	return this->numPeople;
}
char Party::getAccomodation() const {
	return this->accomodation;
}
bool Party::getPromos() const {
	return this->promos;
}
// setters
void Party::setName(char * name) {
	if (this->name) {
		delete [] this->name;
		this->name = nullptr;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Party::setNumPeople(int people) {
	this->numPeople = numPeople;
}
void Party::setAccomodation(char accomodation) {
	this->accomodation = accomodation;
}
void Party::setPromos(bool promo) {
	this->promos = promos;
}
// display
void Party::display() const {
	cout << setw(25) << this->name;
	cout << setw(10) << this->numPeople;
	cout << setw(20);
	if (this->accomodation == 'N') {
		cout << "NO ACCOMODATIONS";
	}
	if (this->accomodation == 'W') {
		cout << "CORKAGE FEE";
	}
	if (this->accomodation == 'C') {
		cout << "BYO CAKE FEE";
	}
	if (this->accomodation == 'H') {
		cout << "HIGH CHAIR NEEDED";
	}
	cout << setw(15);
	if (this->promos) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	cout << endl;
}
