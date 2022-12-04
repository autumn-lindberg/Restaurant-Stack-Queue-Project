#include "main.h"
using namespace std;

int main() {
	char option = 'z';

	Queue * guestList = new Queue();
	Stack * recentGuests = new Stack(3);

	loadGuests(guestList);
	loadRecents(recentGuests);

	while(option != 'q') {
		option = menu();
		executeOption(option, guestList, recentGuests);
	}

	delete guestList;
	delete recentGuests;
}

char menu() {
	char * input = nullptr;
	cout << endl;
	cout << "  QUEUE     - Display Parties Waiting In Line" << endl;
	cout << "  RECENT    - Display Recent Parties" << endl;
	cout << "  PEEK      - Display Most Recent Party" << endl;
	cout << "  ADD       - Add A Party to Queue" << endl;
	cout << "  SEAT      - Seat The First Party In Line" << endl;
	cout << "  CONTACT   - Contact Most Recent Party" << endl;
	cout << "  QUIT      - Quit This Program" << endl;
	cout << endl;
	cout << "Please Enter Your Choice: ";
	input = getWordFromUser();

	for (int i = 0; i < static_cast<int>(strlen(input)); i++) {
		input[i] = toupper(input[i]);
	}
	if (strcmp(input, "QUEUE") == 0) {
		delete [] input;
		return 'w';
	}
	if (strcmp(input, "RECENT") == 0) {
		delete [] input;
		return 'r';
	}
	if (strcmp(input, "PEEK") == 0) {
		delete [] input;
		return 'p';
	}
	if (strcmp(input, "ADD") == 0) {
		delete [] input;
		return 'a';
	}
	if (strcmp(input, "SEAT") == 0) {
		delete [] input;
		return 's';
	}
	if (strcmp(input, "CONTACT") == 0) {
		delete [] input;
		return 'c';
	}
	if (strcmp(input, "QUIT") == 0) {
		delete [] input;
		return 'q';
	}
	else {
		return 'z';
	}
}

void executeOption(char option, Queue *& guestList, Stack *& recentGuests) {
	switch(option) {
		// display queue
		case 'w':
			cout << *(guestList);
			break;
		// display stack
		case 'r':
			cout << *(recentGuests);
			break;
		// display most recent party (peek)
		case 'p':
			recentGuests->peek();
			break;
		// add to queue (enqueue)
		case 'a':
		{
			char * partyName = nullptr;
			int size;
			char accomodations;
			char promos;
			bool promotions;
			cout << endl;
			cout << "Name Of Party: ";
			partyName = getWordFromUser();
			cout << "Size Of Party: ";
			size = getIntFromUser();
			cout << endl;
			cout << "  N   - No Accomodations Needed" << endl;
			cout << "  H   - Request A High Chair" << endl;
			cout << "  C   - Request Cake Service" << endl;
			cout << "  W   - Corkage Fee (BYOB)" << endl;
			cout << endl;
			cout << "What Accomodations Will Your Party Need? ";
			accomodations = getCharFromUser();
			accomodations = toupper(accomodations);
			switch(accomodations) {
				case 'N':
				case 'H':
				case 'C':
				case 'W':
					break;
				default:
					cout << endl;
					cout << "Option Not Recognized. Recording As No Accomodations." << endl;
					cout << endl;
					accomodations = 'N';
			}
			cout << "Receive Promotions? (y / n): ";
			promos = getCharFromUser();
			promos = toupper(promos);
			switch(promos) {
				case 'Y':
					promotions = true;
					break;
				case 'N':
					promotions = false;
					break;
				default:
					cout << endl;
					cout << "Option Not Recognized. Recording As No Promotions." << endl;
					cout << endl;
					promotions = 0;
			}
			Party * p = new Party(partyName, size, accomodations, promotions);
			guestList->enqueue(p);
			delete [] partyName;
			break;
		}
		// remove from queue (dequeue)
		case 's':
			guestList->dequeue(recentGuests);
			break;
		// remove from stack (pop)
		case 'c':
			recentGuests->pop();
			break;
		// quit program
		case 'q':
			cout << endl;
			cout << "Thank You For Using My Program! Goodbye!" << endl;
			cout << endl;
			break;
		default:
			cout << "Choice Not Recognized!" << endl;
			cout << endl;
			break;
	}
}

bool loadGuests(Queue * guestList) {
	ifstream inFile;
	char * name = nullptr;
	int size;
	char accomodation;
	bool promos;
	inFile.open("guests.txt");
	if (!inFile) {
		return false;
	}
	else {
		// post
		name = getWordFromFile(inFile, ',');
		size = getIntFromFile(inFile, ',');
		accomodation = getCharFromFile(inFile, ',');
		accomodation = toupper(accomodation);
		promos = getIntFromFile(inFile, '\n');
		Party * p = new Party(name, size, accomodation, promos);
		guestList->enqueue(p);
		delete [] name;
		// fence and post
		while (inFile.peek() != EOF) {
			name = getWordFromFile(inFile, ',');
			size = getIntFromFile(inFile, ',');
			accomodation = getCharFromFile(inFile, ',');
			accomodation = toupper(accomodation);
			promos = getIntFromFile(inFile, '\n');
			Party * p = new Party(name, size, accomodation, promos);
			guestList->enqueue(p);
			delete [] name;
		}
	}
	inFile.close();
	return true;
}
bool loadRecents(Stack * recentGuests) {
	ifstream inFile;
	char * name = nullptr;
	int size;
	char accomodation;
	bool promos;
	inFile.open("recents.txt");
	if (!inFile) {
		return false;
	}
	else {
		// post
		name = getWordFromFile(inFile, ',');
		size = getIntFromFile(inFile, ',');
		accomodation = getCharFromFile(inFile, ',');
		accomodation = toupper(accomodation);
		promos = getIntFromFile(inFile, '\n');
		Party * p = new Party(name, size, accomodation, promos);
		recentGuests->push(p);
		// fence post
		delete [] name;
		while (inFile.peek() != EOF) {
			name = getWordFromFile(inFile, ',');
			size = getIntFromFile(inFile, ',');
			accomodation = getCharFromFile(inFile, ',');
			accomodation = toupper(accomodation);
			promos = getIntFromFile(inFile, '\n');
			Party * p = new Party(name, size, accomodation, promos);
			recentGuests->push(p);
			delete [] name;
		}
	}
	inFile.close();
	return true;
}
